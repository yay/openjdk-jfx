/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef OriginLock_h
#define OriginLock_h

#if ENABLE(SQL_DATABASE)

#include "FileSystem.h"
#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/ThreadingPrimitives.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class OriginLock : public ThreadSafeRefCounted<OriginLock> {
    WTF_MAKE_NONCOPYABLE(OriginLock); WTF_MAKE_FAST_ALLOCATED;
public:
    OriginLock(String originPath);
    ~OriginLock();

    void lock();
    void unlock();

    static void deleteLockFile(String originPath);

private:
    static String lockFileNameForPath(String originPath);

    String m_lockFileName;
    Mutex m_mutex;
#if USE(FILE_LOCK)
    PlatformFileHandle m_lockHandle;
#endif
};

} // namespace WebCore

#endif // ENABLE(SQL_DATABASE)

#endif // OriginLock_h
