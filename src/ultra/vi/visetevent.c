#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "assert.h"
#include "viint.h"

void osViSetEvent(OSMesgQueue* mq, OSMesg m, u32 retraceCount) {
    register u32 saveMask;

#ifdef _DEBUG
    if (!__osViDevMgr.active) {
        __osError(ERR_OSVISETEVENT, 0);
        return 0;
    }

    assert(mq != NULL);
#endif

    saveMask = __osDisableInt();

    __osViNext->msgq = mq;
    __osViNext->msg = m;
    __osViNext->retraceCount = retraceCount;
    __osRestoreInt(saveMask);
}
