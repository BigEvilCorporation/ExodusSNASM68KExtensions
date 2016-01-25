#ifndef __MegaDriveCOFLOADER_H__
#define __MegaDriveCOFLOADER_H__
#include "Extension/Extension.pkg"

class MegaDriveCOFLoader :public Extension
{
public:
	//Constructors
	MegaDriveCOFLoader(const std::wstring& aimplementationName, const std::wstring& ainstanceName, unsigned int amoduleID);
	~MegaDriveCOFLoader();

	//ROM loading functions
	void LoadROMFile();
	void UnloadROMFile();

	//Window functions
	virtual bool RegisterSystemMenuHandler();
	virtual void AddSystemMenuItems(SystemMenu systemMenu, IMenuSegment& menuSegment);

private:
	//Structures
	struct MegaDriveCOFHeader;

	//View and menu classes
	class FileOpenMenuHandler;
	friend class FileOpenMenuHandler;

private:
	//ROM loading functions
	void UnloadROMFileFromModulePath(const std::wstring& targetROMModulePath) const;

	//ROM module generation
	bool BuildROMFileModuleFromFile(const std::wstring& filePath, IHierarchicalStorageNode& node, std::wstring& romName);
	bool SaveOutputROMModule(IHierarchicalStorageTree& tree, const std::wstring& filePath);

	//ROM analysis functions
	bool LoadROMHeaderFromFile(const std::wstring& filePath, MegaDriveCOFHeader& romHeader, std::vector<char>* rawROMData) const;
	static bool AutoDetectRegionCode(const MegaDriveCOFHeader& romHeader, std::wstring& regionCode);
	static bool AutoDetectBackupRAMSupport(const MegaDriveCOFHeader& romHeader, unsigned int& sramStartLocation, unsigned int& sramByteSize, bool& linkedToEvenAddress, bool& linkedToOddAddress, bool& sram16Bit, std::vector<unsigned char>& initialRAMData);
	static bool StringStartsWith(const std::string& targetString, const std::string& compareString);

private:
	//Menu handling
	FileOpenMenuHandler* menuHandler;

	//Loaded ROM info
	bool selectionMadeThisSession;
	std::list<std::wstring> currentlyLoadedROMModuleFilePaths;
};

#include "MegaDriveCOFLoader.inl"
#endif
