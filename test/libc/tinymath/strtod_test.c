/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│ vi: set et ft=c ts=2 sts=2 sw=2 fenc=utf-8                               :vi │
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2021 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/fmt/conv.h"
#include "libc/macros.internal.h"
#include "libc/mem/gc.h"
#include "libc/mem/mem.h"
#include "libc/runtime/fenv.h"
#include "libc/stdio/stdio.h"
#include "libc/testlib/ezbench.h"
#include "libc/testlib/testlib.h"
#include "libc/x/xasprintf.h"
#include "third_party/double-conversion/wrapper.h"

#define HEX(d) (union Pun){d}.i

union Pun {
  double x;
  uint64_t i;
};

static const struct {
  uint64_t i;
  const char *s;
} V[] = {
    {0x7FF8000000000000, "nan"},                        //
    {0x7FF8000000000000, "NaN"},                        //
    {0x7FF8000000000000, "NAn"},                        //
    {0x7FF8000000000000, "nAN"},                        //
    {0x7FF8000000000000, "NAN"},                        //
    {0x7FF0000000000000, "INF"},                        //
    {0x7FF0000000000000, "iNf"},                        //
    {0x7FF8000000000000, "+NAN"},                       //
    {0xFFF8000000000000, "-NAN"},                       //
    {0x7FF0000000000000, "+INF"},                       //
    {0xFFF0000000000000, "-INF"},                       //
    {0x2fa7b6d71d20b96c, "4e-079"},                     //
    {0x09eb8d7e32be6396, "7e-261"},                     //
    {0x3ae7361cb863de62, "6e-025"},                     //
    {0x1eaf7e0db3799aa3, "7e-161"},                     //
    {0x7c1cbb547777a285, "7e0289"},                     //
    {0x507afcef51f0fb5f, "5e0079"},                     //
    {0x508afcef51f0fb5f, "1e0080"},                     //
    {0x0133339131c46f8b, "7e-303"},                     //
    {0x5fa317e5ef3ab327, "5e0152"},                     //
    {0x5a07a2ecc414a03f, "5e0125"},                     //
    {0x5a27a2ecc414a03f, "2e0126"},                     //
    {0x22d5570f59bd178c, "7e-141"},                     //
    {0x18323ff06eea847a, "4e-192"},                     //
    {0x49102498ea6df0c4, "9e0043"},                     //
    {0x7ed754e31cd072da, "1e0303"},                     //
    {0x2dde3cbc9907fdc8, "95e-089"},                    //
    {0x689d1c26db7d0dae, "85e0194"},                    //
    {0x77c0b7cb60c994da, "69e0267"},                    //
    {0x3c665dde8e688ba6, "97e-019"},                    //
    {0x49d033d7eca0adef, "37e0046"},                    //
    {0x49e033d7eca0adef, "74e0046"},                    //
    {0x2bc0ad836f269a17, "61e-099"},                    //
    {0x151b39ae1909c31b, "53e-208"},                    //
    {0x0fc27b2e4f210075, "93e-234"},                    //
    {0x2c9a5db812948281, "79e-095"},                    //
    {0x0772d36cf48e7abd, "87e-274"},                    //
    {0x4585747ab143e353, "83e0025"},                    //
    {0x38b698ccdc60015a, "17e-036"},                    //
    {0x47246a3418629ef6, "53e0033"},                    //
    {0x30ecd5bee57763e6, "51e-074"},                    //
    {0x3bbdc03b8fd7016a, "63e-022"},                    //
    {0x5e3ae03f245703e2, "839e0143"},                   //
    {0x1abf14727744c63e, "749e-182"},                   //
    {0x3b282782afe1869e, "999e-026"},                   //
    {0x77b0b7cb60c994da, "345e0266"},                   //
    {0x2b5ffc81bc29f02b, "914e-102"},                   //
    {0x55b7221a79cdd1d9, "829e0102"},                   //
    {0x5322d6b183fe4b55, "307e0090"},                   //
    {0x6654374d8b87ac63, "859e0182"},                   //
    {0x5216c309024bab4b, "283e0085"},                   //
    {0x675526be9c22eb17, "589e0187"},                   //
    {0x64fdcf7df8f573b7, "302e0176"},                   //
    {0x650dcf7df8f573b7, "604e0176"},                   //
    {0x0de03cea3586452e, "761e-244"},                   //
    {0x7044d64d4079150c, "647e0230"},                   //
    {0x64a7d93193f78fc6, "755e0174"},                   //
    {0x30dcd5bee57763e6, "255e-075"},                   //
    {0x7FF0000000000000, "INFINITY"},                   //
    {0x7FF0000000000000, "iNfiNiTy"},                   //
    {0x7FF0000000000000, "+INFINITY"},                  //
    {0xFFF0000000000000, "-INFINITY"},                  //
    {0x4c159bd3ad46e346, "3391e0055"},                  //
    {0x3d923d1b5eb1d778, "4147e-015"},                  //
    {0x3b482782afe1869e, "3996e-026"},                  //
    {0x3b382782afe1869e, "1998e-026"},                  //
    {0x0335519ac5142aab, "3338e-296"},                  //
    {0x0325519ac5142aab, "1669e-296"},                  //
    {0x0772d2df246ecd2d, "8699e-276"},                  //
    {0x73284e91f4aa0fdb, "5311e0243"},                  //
    {0x2cd07c2d27a5b989, "7903e-096"},                  //
    {0x11d19b8744033457, "7611e-226"},                  //
    {0x4cb444b34a6fb3eb, "3257e0058"},                  //
    {0x4cc444b34a6fb3eb, "6514e0058"},                  //
    {0x77462644c61d41aa, "3571e0263"},                  //
    {0x77562644c61d41aa, "7142e0263"},                  //
    {0x72f3720e5d54d97c, "5311e0242"},                  //
    {0x3384c98fce16152e, "1617e-063"},                  //
    {0x4897d2950dc76da4, "51881e0037"},                 //
    {0x285ef890f5de4c86, "31441e-118"},                 //
    {0x5143e272a77478e8, "30179e0079"},                 //
    {0x5153e272a77478e8, "60358e0079"},                 //
    {0x3cc703856844bdbf, "63876e-020"},                 //
    {0x3cb703856844bdbf, "31938e-020"},                 //
    {0x3a42405b773fbdf3, "46073e-032"},                 //
    {0x4b757eb8ad52a5c9, "32941e0051"},                 //
    {0x49770105df3d47cb, "82081e0041"},                 //
    {0x1440492a4a8a37fd, "38701e-215"},                 //
    {0x4ab0c52fe6dc6a1b, "62745e0047"},                 //
    {0x4ac0c52fe6dc6a1b, "12549e0048"},                 //
    {0x1af099b393b84832, "64009e-183"},                 //
    {0x77262644c61d41aa, "89275e0261"},                 //
    {0x46232645e1ba93f0, "75859e0025"},                 //
    {0x7c8272ed2307f56a, "57533e0287"},                 //
    {0x70ad657059dc79aa, "584169e0229"},                //
    {0x29eb99d6240c1a28, "940189e-112"},                //
    {0x6a00fd07ed297f80, "416121e0197"},                //
    {0x6a10fd07ed297f80, "832242e0197"},                //
    {0x50e8a85eb277e645, "584738e0076"},                //
    {0x241b248728b9c117, "933587e-140"},                //
    {0x5a2dda592e398dd7, "252601e0121"},                //
    {0x79f9463b59b8f2bd, "358423e0274"},                //
    {0x14f25818c7294f27, "892771e-213"},                //
    {0x49670105df3d47cb, "410405e0040"},                //
    {0x0afbe2dd66200bef, "928609e-261"},                //
    {0x0c55a462d91c6ab3, "302276e-254"},                //
    {0x3c653a9985dbde6c, "920657e-023"},                //
    {0x3bf1f99e11ea0a24, "609019e-025"},                //
    {0x59f7e1e0f1c7a4ac, "252601e0120"},                //
    {0x34b00e7db3b3f242, "654839e-060"},                //
    {0x5c5e597c0b94b7ae, "8823691e0130"},               //
    {0x709d657059dc79aa, "2920845e0228"},               //
    {0x51fda232347e6032, "9210917e0080"},               //
    {0x026e58ffa48f4fce, "5800419e-303"},               //
    {0x0ee3ecf22ea07863, "6119898e-243"},               //
    {0x0ed3ecf22ea07863, "3059949e-243"},               //
    {0x6f90f73be1dff9ad, "2572231e0223"},               //
    {0x3cf8849dd33c95af, "5444097e-021"},               //
    {0x26f7e5902ce0e151, "5783893e-127"},               //
    {0x1295d4fe53afec65, "3865421e-225"},               //
    {0x61b4689b4a5fa201, "4590831e0156"},               //
    {0x61c4689b4a5fa201, "9181662e0156"},               //
    {0x3bbbe45a312d08a0, "5906361e-027"},               //
    {0x7225f0d408362a72, "7315057e0235"},               //
    {0x5762e51a84a3c6a0, "9088115e0106"},               //
    {0x5772e51a84a3c6a0, "1817623e0107"},               //
    {0x5c4e597c0b94b7ae, "44118455e0129"},              //
    {0x7e5512d5273e62e8, "35282041e0293"},              //
    {0x05129b01b6885d36, "31279898e-291"},              //
    {0x05029b01b6885d36, "15639949e-291"},              //
    {0x5f955bcf72fd10f9, "27966061e0145"},              //
    {0x5fa55bcf72fd10f9, "55932122e0145"},              //
    {0x36900683a21de855, "70176353e-053"},              //
    {0x3adf29ca0ff893b1, "40277543e-032"},              //
    {0x622193aff1f1c8e3, "50609263e0157"},              //
    {0x518b37c4b7928317, "66094077e0077"},              //
    {0x59406e98f5ec8f37, "84863171e0114"},              //
    {0x786526f061ca9053, "89396333e0264"},              //
    {0x016e07320602056c, "87575437e-309"},              //
    {0x3870bc7b7603a2ca, "78693511e-044"},              //
    {0x16d1470083f89d48, "90285923e-206"},              //
    {0x3b423a4ad20748a2, "30155207e-030"},              //
    {0x5acc569e968e0944, "245540327e0121"},             //
    {0x7d44997a298b2f2e, "263125459e0287"},             //
    {0x0c64472ba9550e86, "566446538e-257"},             //
    {0x0c54472ba9550e86, "283223269e-257"},             //
    {0x5b01b6231e18c5cb, "245540327e0122"},             //
    {0x5b11b6231e18c5cb, "491080654e0122"},             //
    {0x27a397d3c9745d2f, "971212611e-126"},             //
    {0x4c76ce94febdc7a5, "229058583e0052"},             //
    {0x49cc7ccf90c9f8ab, "325270231e0039"},             //
    {0x3a8880a3d515e849, "989648089e-035"},             //
    {0x7a720223f2b3a881, "653777767e0273"},             //
    {0x6d30bc60e6896717, "923091487e0209"},             //
    {0x7d89bfd8b3edfafa, "526250918e0288"},             //
    {0x018e07320602056c, "350301748e-309"},             //
    {0x17a14fe7daf8f3ae, "741111169e-203"},             //
    {0x0ff09355f8050c02, "667284113e-240"},             //
    {0x5abc569e968e0944, "1227701635e0120"},            //
    {0x1c38afe10a2a66aa, "9981396317e-182"},            //
    {0x041465b896c24520, "5232604057e-298"},            //
    {0x2fb0847822f765b2, "5572170023e-088"},            //
    {0x5b31b6231e18c5cb, "1964322616e0122"},            //
    {0x5b41b6231e18c5cb, "3928645232e0122"},            //
    {0x35f4614c3219891f, "8715380633e-058"},            //
    {0x279397d3c9745d2f, "4856063055e-127"},            //
    {0x223a06a1024b95e1, "8336960483e-153"},            //
    {0x21a01891fc4717fd, "1007046393e-155"},            //
    {0x1d695fd4c88d4b1b, "5378822089e-176"},            //
    {0x1a83db11ac608107, "5981342308e-190"},            //
    {0x3020b552d2edcdea, "7214782613e-086"},            //
    {0x5f70acde6a98eb4c, "5458466829e0142"},            //
    {0x2b5fc575867314ee, "9078555839e-109"},            //
    {0x526021f14ed7b3fa, "6418488827e0079"},            //
    {0x5081a151ddbd3c4a, "65325840981e0069"},           //
    {0x54a221bd871d2cf4, "49573485983e0089"},           //
    {0x51830e6c7d4e3480, "46275205733e0074"},           //
    {0x51930e6c7d4e3480, "92550411466e0074"},           //
    {0x1832c3e72d179607, "41129842097e-202"},           //
    {0x380960fe08d5847f, "93227267727e-049"},           //
    {0x688c49437fccfadb, "41297294357e0185"},           //
    {0x343a12666477886d, "41534892987e-067"},           //
    {0x6be0189a26df575f, "42333842451e0201"},           //
    {0x131155515fd37265, "78564021519e-227"},           //
    {0x35800a19a3ffd981, "53587107423e-061"},           //
    {0x18a32fa69a69bd6d, "53827010643e-200"},           //
    {0x6a4544e6daee2a18, "83356057653e0193"},           //
    {0x29a541ecdfd48694, "45256834646e-118"},           //
    {0x2b4fc575867314ee, "45392779195e-110"},           //
    {0x7e81deaf40ead9a0, "23934638219e0291"},           //
    {0x59e2d44edcc51304, "995779191233e0113"},          //
    {0x0b676688faee99bc, "997422852243e-265"},          //
    {0x28d925a0aabcdc68, "653532977297e-123"},          //
    {0x60f11894b202e9f4, "938885684947e0147"},          //
    {0x5c210c20303fe0f1, "619534293513e0124"},          //
    {0x39a5e66dc3d6bdb5, "539879452414e-042"},          //
    {0x782c1c352fc3c309, "742522891517e0259"},          //
    {0x3dbc06d366394441, "254901016865e-022"},          //
    {0x7c85fd7aa44d9477, "685763015669e0280"},          //
    {0x072aa65b58639e69, "384865004907e-285"},          //
    {0x5321958b36c5102b, "286556458711e0081"},          //
    {0x5331958b36c5102b, "573112917422e0081"},          //
    {0x234253ec0e161420, "769525178383e-150"},          //
    {0x6a3544e6daee2a18, "416780288265e0192"},          //
    {0x2b3fc575867314ee, "226963895975e-111"},          //
    {0x4f778b6516c2b478, "665592809339e0063"},          //
    {0x6f99ab8261990292, "3891901811465e0217"},         //
    {0x50e4177a9915fbf8, "4764593340755e0069"},         //
    {0x7a7173f76c63b792, "6336156586177e0269"},         //
    {0x56566fee05649a7a, "8233559360849e0095"},         //
    {0x2c538e6edd48f2a3, "3662265515198e-107"},         //
    {0x2c438e6edd48f2a3, "1831132757599e-107"},         //
    {0x1d726dae7bbeda75, "7812878489261e-179"},         //
    {0x60b28a61cf9483b7, "6363857920591e0145"},         //
    {0x53a51f508b287ae7, "8811915538555e0082"},         //
    {0x1a253db2fea1ea31, "9997878507563e-195"},         //
    {0x0634ee5d56b32957, "9224786422069e-291"},         //
    {0x058d3409dfbca26f, "6284426329974e-294"},         //
    {0x35c135972630774c, "9199302046091e-062"},         //
    {0x29423fa9e6fcf47e, "6070482281213e-122"},         //
    {0x0405acc2053064c2, "2780161250963e-301"},         //
    {0x5621f324d11d4862, "8233559360849e0094"},         //
    {0x6d94677812d3a606, "72027097041701e0206"},        //
    {0x6f79ab8261990292, "97297545286625e0215"},        //
    {0x3da5c6714def374c, "99021992302453e-025"},        //
    {0x3e373cdf8db7a7bc, "54104687080198e-022"},        //
    {0x5537f203339c9629, "33519685743233e0089"},        //
    {0x5547f203339c9629, "67039371486466e0089"},        //
    {0x1d626dae7bbeda75, "39064392446305e-180"},        //
    {0x78e072f3819c1321, "17796979903653e0261"},        //
    {0x4a9eebabe0957af3, "28921916763211e0038"},        //
    {0x6302920f96e7f9ef, "87605699161665e0155"},        //
    {0x34d9b2a5c4041e4b, "41921560615349e-067"},        //
    {0x4f7c7c5aea080a49, "80527976643809e0061"},        //
    {0x21cce77c2b3328fc, "72335858886654e-159"},        //
    {0x57f561def4a9ee32, "52656615219377e0102"},        //
    {0x33b8bf7e7fa6f02a, "15400733123779e-072"},        //
    {0x33a8bf7e7fa6f02a, "77003665618895e-073"},        //
    {0x3a42d73088f4050a, "475603213226859e-042"},       //
    {0x5b218a7f36172332, "972708181182949e0116"},       //
    {0x342eef5e1f90ac34, "246411729980464e-071"},       //
    {0x341eef5e1f90ac34, "123205864990232e-071"},       //
    {0x0e104273b18918b1, "609610927149051e-255"},       //
    {0x3a778cfcab31064d, "475603213226859e-041"},       //
    {0x508226c684c87261, "672574798934795e0065"},       //
    {0x509226c684c87261, "134514959786959e0066"},       //
    {0x2395f2df5e675a0f, "294897574603217e-151"},       //
    {0x4a7eebabe0957af3, "723047919080275e0036"},       //
    {0x30bddc7e975c5045, "660191429952702e-088"},       //
    {0x30addc7e975c5045, "330095714976351e-088"},       //
    {0x21fce77c2b3328fc, "578686871093232e-159"},       //
    {0x21dce77c2b3328fc, "144671717773308e-159"},       //
    {0x3398bf7e7fa6f02a, "385018328094475e-074"},       //
    {0x3077e3987916a69e, "330095714976351e-089"},       //
    {0x171a80a6e566428c, "2215901545757777e-212"},      //
    {0x09cacc46749dccfe, "1702061899637397e-276"},      //
    {0x6f53ae60753af6ca, "1864950924021923e0213"},      //
    {0x6f63ae60753af6ca, "3729901848043846e0213"},      //
    {0x20f8823a57adbef9, "7487252720986826e-165"},      //
    {0x20e8823a57adbef9, "3743626360493413e-165"},      //
    {0x5be5f6de9d5d6b5b, "4988915232824583e0119"},      //
    {0x7cae3c14d6916ce9, "3771476185376383e0277"},      //
    {0x2a81b96458445d07, "6182410494241627e-119"},      //
    {0x609dfc11fbf46087, "2572981889477453e0142"},      //
    {0x4dd280461b856ec5, "7793560217139653e0051"},      //
    {0x194fe601457dce4d, "9163942927285259e-202"},      //
    {0x63650aff653ffe8a, "6353227084707473e0155"},      //
    {0x176090684f5fe998, "4431803091515554e-211"},      //
    {0x6f0f7d6721f7f144, "9324754620109615e0211"},      //
    {0x79d90529a37b7e22, "8870461176410409e0263"},      //
    {0x612491daad0ba280, "90372559027740405e0143"},     //
    {0x61a011f2d73116f4, "18074511805548081e0146"},     //
    {0x496ec55666d8f9ec, "54897030182071313e0029"},     //
    {0x3ccb7738011e75fe, "76232626624829156e-032"},     //
    {0x2128823a57adbef9, "59898021767894608e-165"},     //
    {0x2118823a57adbef9, "29949010883947304e-165"},     //
    {0x4d83de005bd620df, "26153245263757307e0049"},     //
    {0x0d27c0747bd76fa1, "27176258005319167e-261"},     //
    {0x61d4166f8cfd5cb1, "18074511805548081e0147"},     //
    {0x2b759a2783ce70ab, "24691002732654881e-115"},     //
    {0x4f408ce499519ce3, "58483921078398283e0057"},     //
    {0x22692238f7987779, "64409240769861689e-159"},     //
    {0x11364981e39e66ca, "94080055902682397e-242"},     //
    {0x63550aff653ffe8a, "31766135423537365e0154"},     //
    {0x657a999ddec72aca, "68985865317742005e0164"},     //
    {0x658a999ddec72aca, "13797173063548401e0165"},     //
    {0x09522dc01ca1cb8c, "902042358290366539e-281"},    //
    {0x7c038fd93f1f5342, "238296178309629163e0272"},    //
    {0x72925ae62cb346d8, "783308178698887621e0226"},    //
    {0x499ec55666d8f9ec, "439176241456570504e0029"},    //
    {0x7e6adf51fa055e03, "899810892172646163e0283"},    //
    {0x14f307a67f1f69ff, "926145344610700019e-225"},    //
    {0x4d63de005bd620df, "653831131593932675e0047"},    //
    {0x4d73de005bd620df, "130766226318786535e0048"},    //
    {0x0693bfac6bc4767b, "557035730189854663e-294"},    //
    {0x0986b93023ca3e6f, "902042358290366539e-280"},    //
    {0x6d13bbb4bf05f087, "272104041512242479e0200"},    //
    {0x6d23bbb4bf05f087, "544208083024484958e0200"},    //
    {0x6b808ebc116f8a20, "680429695511221511e0192"},    //
    {0x7490db75cc001072, "308975121073410857e0236"},    //
    {0x53d7bff336d8ff06, "792644927852378159e0078"},    //
    {0x71f2cbac35f71140, "783308178698887621e0223"},    //
    {0x0f8ab223efcee35a, "8396094300569779681e-252"},   //
    {0x346b85c026a264e4, "3507665085003296281e-074"},   //
    {0x5336775b6caa5ae0, "7322325862592278999e0074"},   //
    {0x6f396397b06732a4, "6014546754280072926e0209"},   //
    {0x5cc3220dcd5899fd, "7120190517612959703e0120"},   //
    {0x34a1339818257f0f, "3507665085003296281e-073"},   //
    {0x168a9c42e5b6d89f, "4345544743100783551e-218"},   //
    {0x313146fe1075e1ef, "9778613303868468131e-090"},   //
    {0x32d3d969e3dbe723, "7539204280836061195e-082"},   //
    {0x19eaba3262ee707b, "7862637540082247119e-202"},   //
    {0x6d43bbb4bf05f087, "2176832332097939832e0200"},   //
    {0x5bbe71ec1ed0a4f9, "8643988913946659879e0115"},   //
    {0x6079c677be6f236e, "5529436763613147623e0138"},   //
    {0x1fed06692e6f5ef6, "6764958008109694533e-173"},   //
    {0x6cbf92bacb3cb40c, "6802601037806061975e0197"},   //
    {0x6ccf92bacb3cb40c, "1360520207561212395e0198"},   //
    {0x4dcd8f2cfc20d6e8, "62259110684423957791e0047"},  //
    {0x1526cec51a43f41a, "88800290202542652011e-226"},  //
    {0x162012954b6aabba, "41010852717673354694e-221"},  //
    {0x161012954b6aabba, "20505426358836677347e-221"},  //
    {0x4f7762068a24fd55, "66102447903809911604e0055"},  //
    {0x5cb3220dcd5899fd, "35600952588064798515e0119"},  //
    {0x6e78d92d2bcc7a81, "14371240869903838702e0205"},  //
    {0x4cf65d3e2acd616b, "57500690832492901689e0043"},  //
    {0x2dbdd54c40a2f25f, "23432630639573022093e-107"},  //
    {0x4e02797c1d948651, "62259110684423957791e0048"},  //
    {0x0475b22082529425, "35620497849450218807e-306"},  //
    {0x6d93bbb4bf05f087, "69658634627134074624e0200"},  //
    {0x37362d10462a26f4, "99440755792436956989e-062"},  //
    {0x54d945bfa911e32a, "55277197169490210673e0081"},  //
    {0x01f8c5f9551c2f9a, "36992084760177624177e-318"},  //
    {0x2cf01b8ef28251fc, "30888265282878466443e-111"},  //
};

int oldround;

void SetUp(void) {
  oldround = fegetround();
}

void TearDown(void) {
  fesetround(oldround);
}

TEST(strtod, test) {
  int i;
  for (i = 0; i < ARRAYLEN(V); ++i) {
    EXPECT_EQ(V[i].i, HEX(strtod(V[i].s, 0)), "strtod(%`'s)", V[i].s);
  }
}

TEST(strtod, testNearest) {
  fesetround(FE_TONEAREST);
  EXPECT_STREQ("-1.79769313486231e+308",
               gc(xasprintf("%.15g", strtod("-1.79769313486231e+308", NULL))));
}

TEST(strtod, testDownward) {
  fesetround(FE_DOWNWARD);
  EXPECT_STREQ("-1.79769313486232e+308",
               gc(xasprintf("%.15g", strtod("-1.79769313486231e+308", NULL))));
}

TEST(strtod, testUpward) {
  fesetround(FE_UPWARD);
  EXPECT_STREQ("-1.7976931348623e+308",
               gc(xasprintf("%.15g", strtod("-1.79769313486231e+308", NULL))));
}

TEST(strtod, testTowardzero) {
  char *p;
  for (int i = 0; i < 9999; ++i) {
    fesetround(FE_TOWARDZERO);
    EXPECT_STREQ(
        "-1.7976931348623e+308",
        (p = xasprintf("%.15g", strtod("-1.79769313486231e+308", NULL))));
    fesetround(FE_TONEAREST);
    free(p);
  }
}

BENCH(strtod, bench) {
  char buf[128];
  EZBENCH2("strtod", donothing, strtod("-1.79769313486231e+308", 0));
  EZBENCH2("StringToDouble", donothing,
           StringToDouble("-1.79769313486231e+308", 22, 0));
  EZBENCH2("snprintf %g", donothing,
           snprintf(buf, 128, "%g", -1.79769313486231e+308));
  EZBENCH2("DoubleToEcmascript", donothing,
           DoubleToEcmascript(buf, -1.79769313486231e+308));
}
