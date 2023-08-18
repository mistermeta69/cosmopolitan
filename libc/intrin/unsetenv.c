/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
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
#include "libc/dce.h"
#include "libc/intrin/getenv.internal.h"
#include "libc/runtime/runtime.h"
#include "libc/sysv/errfuns.h"

/**
 * Removes environment variable.
 *
 * @param s is non-empty environment key which can't contain `'='`
 * @return 0 on success, or -1 w/ errno and environment is unchanged
 * @raise EINVAL if `s` is an empty string or has a `'='` character
 */
int unsetenv(const char *s) {
  char **p, *t;
  struct Env e;
  if (!s || !*s) return einval();
  for (t = s; *t; ++t) {
    if (*t == '=') return einval();
  }
  if ((p = environ)) {
    e = __getenv(p, s);
    while (p[e.i]) {
      p[e.i] = p[e.i + 1];
      ++e.i;
    }
  }
  return 0;
}
