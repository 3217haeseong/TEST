#pragma once
#include <string>
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	void RenderBegin();
	void RenderEnd();

private:
	// 장치와 스왑체인 생성
	void CreateDeviceAndSwapChain();
	// 렌더링될 곳으로 후면버퍼 지정
	void CreateRenderTargetView();

	// 뷰포트의 크기 지정을 위한 함수.
	void SetViewport();

private:
	// 정점 데이터를 만들어 줌.
	void CreateGeometry();
	// 파이프라인 과정에서 건네주는 데이터에 대한 레이아웃을 알려주는 함수.
	void CreateInputLayout();

	void LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);



private:
	HWND _hwnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// DX
	ComPtr<ID3D11Device> _device;
	ComPtr<ID3D11DeviceContext> _deviceContext;
	ComPtr<IDXGISwapChain> _swapChain = nullptr;

	// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;

	// Misc
	D3D11_VIEWPORT _viewport = { 0 };
	float _clearColor[4] = { 0.5f,0.5f,0.5f,0.5f };

private:
	// Geometry
	vector<Vertex> _vertices;
	// GPU의 VRAM에 데이터를 넣기 위한 변수
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;
	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;
	
	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _osBlob = nullptr;

};

