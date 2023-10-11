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
#include "libc/calls/sig.internal.h"
#include "libc/calls/struct/sigset.internal.h"
#include "libc/calls/struct/stat.h"
#include "libc/calls/struct/stat.internal.h"
#include "libc/calls/syscall_support-nt.internal.h"
#include "libc/errno.h"
#include "libc/nt/createfile.h"
#include "libc/nt/enum/accessmask.h"
#include "libc/nt/enum/creationdisposition.h"
#include "libc/nt/enum/fileflagandattributes.h"
#include "libc/nt/enum/filesharemode.h"
#include "libc/nt/errors.h"
#include "libc/nt/runtime.h"
#include "libc/sysv/consts/at.h"

textwindows int sys_fstatat_nt(int dirfd, const char *path, struct stat *st,
                               int flags) {
  int rc, e;
  int64_t fh;
  uint32_t dwDesiredAccess;
  uint16_t path16[PATH_MAX];
  if (__mkntpathat(dirfd, path, 0, path16) == -1) return -1;
  BLOCK_SIGNALS;
  e = errno;
  dwDesiredAccess = kNtFileGenericRead;
TryAgain:
  if ((fh = CreateFile(
           path16, dwDesiredAccess, 0, 0, kNtOpenExisting,
           kNtFileAttributeNormal | kNtFileFlagBackupSemantics |
               ((flags & AT_SYMLINK_NOFOLLOW) ? kNtFileFlagOpenReparsePoint
                                              : 0),
           0)) != -1) {
    rc = st ? sys_fstat_nt(fh, st) : 0;
    CloseHandle(fh);
  } else if (dwDesiredAccess == kNtFileGenericRead &&
             GetLastError() == kNtErrorSharingViolation) {
    dwDesiredAccess = kNtFileReadAttributes;
    errno = e;
    goto TryAgain;
  } else {
    rc = __winerr();
  }
  ALLOW_SIGNALS;
  return __fix_enotdir(rc, path16);
}
