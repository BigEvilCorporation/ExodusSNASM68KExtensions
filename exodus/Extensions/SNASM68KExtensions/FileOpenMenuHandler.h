#include "MegaDriveCOFLoader.h"
#ifndef __MegaDriveCOFLOADER_FILEOPENMENUHANDLER_H__
#define __MegaDriveCOFLOADER_FILEOPENMENUHANDLER_H__
#include "DeviceInterface/DeviceInterface.pkg"

class MegaDriveCOFLoader::FileOpenMenuHandler :public MenuHandlerBase
{
public:
	//Enumerations
	enum MenuItem
	{
		MENUITEM_OPENMegaDriveCOF,
		MENUITEM_CLOSEMegaDriveCOF
	};

public:
	//Constructors
	FileOpenMenuHandler(MegaDriveCOFLoader& aextension);

protected:
	//Management functions
	virtual void GetMenuItems(std::list<MenuItemDefinition>& menuItems) const;
	virtual IViewPresenter* CreateViewForItem(int menuItemID, const std::wstring& viewName);
	virtual void DeleteViewForItem(int menuItemID, IViewPresenter* viewPresenter);
	virtual void HandleMenuItemSelectNonView(int menuItemID, IViewManager& aviewManager);

private:
	MegaDriveCOFLoader& extension;
};

#endif
