#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <Windows.h>

OGame::OGame()
{
	m_display = std::unique_ptr <OWindow>(new OWindow());
}

OGame::~OGame()
{
}

void OGame::quit()
{
	m_isRunnig = false;

}

void OGame::run()
{
	MSG msg;
	while (m_isRunnig && !m_display->isClosed())
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
		Sleep(1);
	}
}
