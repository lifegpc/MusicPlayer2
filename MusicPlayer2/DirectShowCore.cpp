#include "DirectShowCore.h"

#if ENABLE_DIRECTSHOW_CORE
#pragma comment(lib, "Strmiids.lib")

/// ����Filter�ã�����MPC-HCԴ����
#define BeginEnumFilters(pFilterGraph, pEnumFilters, pBaseFilter) { \
    CComPtr<IEnumFilters> pEnumFilters; \
    if (pFilterGraph && SUCCEEDED(pFilterGraph->EnumFilters(&pEnumFilters))) {  \
        for (CComPtr<IBaseFilter> pBaseFilter; S_OK == pEnumFilters->Next(1, &pBaseFilter, 0); pBaseFilter = nullptr) {
/// ��������
#define EndEnumFilters }}}

CDirectShowCore::CDirectShowCore() {
}

CDirectShowCore::~CDirectShowCore() {
}

void CDirectShowCore::InitCore() {
    // ��ʼ��COM
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr)) {
        have_fatal_error = true;
        errmsg = L"Failed to initialize COM library.";
        return;
    }
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr)) {
        have_fatal_error = true;
        errmsg = L"Could not create the Filter Graph Manager.";
        return;
    }
    pGraph->QueryInterface(&pControl);
    pGraph->QueryInterface(&pEvent);
    m_initailzed = true;
}

void CDirectShowCore::UnInitCore() {

}

unsigned int CDirectShowCore::GetHandle() {
    return 0;
}

std::wstring CDirectShowCore::GetAudioType() {
    return L"";
}

#endif
