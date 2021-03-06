#include <shlobj.h>

extern LONG objs_loaded;

class BtrfsIconOverlay : public IShellIconOverlayIdentifier {
public:
    BtrfsIconOverlay() {
        refcount = 0;
        InterlockedIncrement(&objs_loaded);
    }

    virtual ~BtrfsIconOverlay() {
        InterlockedDecrement(&objs_loaded);
    }

    // IUnknown
    
    HRESULT __stdcall QueryInterface(REFIID riid, void **ppObj);
    
    ULONG __stdcall AddRef() {
        return InterlockedIncrement(&refcount);
    }

    ULONG __stdcall Release() {
        LONG rc = InterlockedDecrement(&refcount);
        
        if (rc == 0)
            delete this;
        
        return rc;
    }

    // IShellIconOverlayIdentifier
    
    virtual HRESULT __stdcall GetOverlayInfo(PWSTR pwszIconFile, int cchMax, int* pIndex, DWORD* pdwFlags);
    virtual HRESULT __stdcall GetPriority(int *pPriority);
    virtual HRESULT __stdcall IsMemberOf(PCWSTR pwszPath, DWORD dwAttrib);

private:
    LONG refcount;
};
