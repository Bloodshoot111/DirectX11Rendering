#pragma once
#include "CustomWin.h"
#include "CustomException.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <optional>
#include <memory>

class Window
{
private:
	
	class Exception : public CustomException
	{
		using CustomException::CustomException;
	public:
		static std::string TranslateErrorCode(HRESULT hr) noexcept;	
	};
public:
	class HrException : public Exception
	{
	public:
		HrException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};
	//singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const wchar_t* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;

	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const Window&) = delete;
		static constexpr const wchar_t* wndCLassName = L"DirectX11 Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
	Window(int width, int height, const wchar_t* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	void SetTitle(const std::wstring& title);
	static std::optional<int> ProcessMessages() noexcept;
	Graphics& Gfx();
	
private:
	static LRESULT WINAPI HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT WINAPI HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
public:
	Keyboard kbd;
	Mouse mouse;
private:
	int width;
	int height;
	HWND hWnd;
	std::unique_ptr<Graphics> pGfx;
public:
	//error exception helper macro
#define CUWND_EXCEPT( hr ) Window::HrException( __LINE__,__FILE__,(hr) )
#define CUWND_LAST_EXCEPT() Window::HrException( __LINE__,__FILE__,GetLastError() )
#define CUWND_NOGFX_EXCEPT() Window::NoGfxException( __LINE__,__FILE__ ) 
};

