#pragma once
#include "IPlayerCore.h"

#if ENABLE_DIRECTSHOW_CORE

#include <dshow.h>

class CDirectShowCore : public IPlayerCore {
public:
    CDirectShowCore();
    ~CDirectShowCore();
    virtual void InitCore() override;
    virtual void UnInitCore() override;
    virtual unsigned int GetHandle() override;
    virtual std::wstring GetAudioType() override;
private:
    bool m_initailzed = false;
    bool have_fatal_error = false;
    std::wstring errmsg;
    /// 用于控制渲染文件
    CComPtr<IGraphBuilder> pGraph;
    CComQIPtr<IMediaControl> pControl;
    CComQIPtr<IMediaEvent> pEvent;
    CComQIPtr<IBasicAudio> pAudio;
};
#endif
