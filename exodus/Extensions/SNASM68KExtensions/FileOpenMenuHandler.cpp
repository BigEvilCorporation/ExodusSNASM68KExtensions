#include "FileOpenMenuHandler.h"

//----------------------------------------------------------------------------------------
//Constructors
//----------------------------------------------------------------------------------------
MegaDriveCOFLoader::FileOpenMenuHandler::FileOpenMenuHandler(MegaDriveCOFLoader& aextension)
:MenuHandlerBase(L"MegaDriveCOFLoaderFileOpenMenu", aextension.GetViewManager()), extension(aextension)
{}

//----------------------------------------------------------------------------------------
//Management functions
//----------------------------------------------------------------------------------------
void MegaDriveCOFLoader::FileOpenMenuHandler::GetMenuItems(std::list<MenuItemDefinition>& menuItems) const
{
	menuItems.push_back(MenuItemDefinition(MENUITEM_OPENMegaDriveCOF, L"OpenMegaDriveCOF", L"Open Mega Drive ROM", false));
	menuItems.push_back(MenuItemDefinition(MENUITEM_CLOSEMegaDriveCOF, L"CloseMegaDriveCOF", L"Close Mega Drive ROM", false));
}

//----------------------------------------------------------------------------------------
IViewPresenter* MegaDriveCOFLoader::FileOpenMenuHandler::CreateViewForItem(int menuItemID, const std::wstring& viewName)
{
	return 0;
}

//----------------------------------------------------------------------------------------
void MegaDriveCOFLoader::FileOpenMenuHandler::DeleteViewForItem(int menuItemID, IViewPresenter* viewPresenter)
{
	delete viewPresenter;
}

//----------------------------------------------------------------------------------------
void MegaDriveCOFLoader::FileOpenMenuHandler::HandleMenuItemSelectNonView(int menuItemID, IViewManager& aviewManager)
{
	switch(menuItemID)
	{
	case MENUITEM_OPENMegaDriveCOF:
		extension.LoadROMFile();
		break;
	case MENUITEM_CLOSEMegaDriveCOF:
		extension.UnloadROMFile();
		break;
	}
}
