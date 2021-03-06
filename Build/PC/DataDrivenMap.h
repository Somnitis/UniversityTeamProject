/*                      (.      ,(,                                        
                     ,(*       (     ,#/  (%    ,%*.                   
                 .%(        ,&*#     *( .* .&/ /#%& ,,    ,/             
               ,@*,,.      %(% %.%#,#%/ /@, /,*(#%(,.&,                  
               #   ,(&      %,,% ((    ##&&/,      #.##      .         
       #/    (%(    .%   ,,(%. ,         ,.         %(#*#.  #%&@,        
        . ,#(/,     #%#.#.%,                           ,(&,, %/.       
          ,/,        .**,.                               (#,   ,%        
      .#%  ,,         ,,         #*                       ,#   /&@%%.    
      %,*%%*                   ##  ##    %@@@@@@@@@@@@@@@@@*##   /#.%    
      ,*       %, @*          .,&%%&,.   %%(%%%%%%%%%%%%%%%.*#.    #.    
     ,*        %,  #*           %%%%     %%%%             ,#       *(    
    ,%*,*#     %,%@*#&          %%%%     %%%%                     ,..    
    .,., ,,    %,%*&**&         %%%%     %%%%                      .#    
     ,,#,#.    %,%, &&*@        %%%%     %%%%                    ,%##  ,%
      #        %,%,  *#.@*      %%%%     %%%%         ,@#          %%.,&*
    %(#.%.     %,%,   #@ &*     %%%%     %%.,,,,,,,,,,,. @#      ,@,     
   ,, % %,     %,%,    *& @#    %%%%     %%(%%%%%%%%%%%(*#.       .,,#   
 .&,(. ,.      %,%,     *@ ##   %%%%     %%%%         .#         %/*#   
  *#  *&       %,%,      .@.#@  %%%%     %%%%                        /,  
   .#/         %,%,       .@..@.%%%%     %%%%                     /#*    
  %%((         %,%,         @#.@@%%%     %%%%                     ,*,    
  (            %,%,          #* @%%%     %%%%                     (@(    
    #.         %,%,           #&  %%     %%%%                     *%%,   
 (* %.       #@%.(@@.        NIKOLAOS   FRAGKAS                  .#      
(              #(@*       DataDrivenMap  Class                 */
//							  12/ 03 / 2018
#pragma once
#include <string>																				
#include <fstream>
#include <vector>																				
#include <iterator>	
#include "Map.h"


class DataDrivenMap :public Map
{
private:
	float m_AccumTime;
	uint activePickups;
	uint activeCapture;
	uint linenum;
	Map* map;
	string fileName;
	string mapName;
	vector<string> lines;
	TEXTURETYPE textureID[10];
	int textID;

	Colour team;
	PickupType type;
	WeaponType weapType;
	Vector3 sPotision[4];

	// Building Functions
	vector<string> GetLines(std::string file);
	vector<string> GetObjects(std::string line);

	void ReadFile();
	void Buildmap();
	void BuildObjects();
	void BuildObject(vector<std::string> object);
	void BuildMapDimenions(vector<std::string> object);
	void AddGround(vector<std::string> object);
	void AddCuboid(vector<std::string> object);
	void SetSpawnLocation(vector<std::string> object);
	void AddPaintPools(vector<std::string> object);
	void AddPickups(vector<std::string> object);
	void AddWeaponPickups(vector<std::string> object);
	void AddCaptureAreas(vector<std::string> object);
	void AddMultiPaintPools(vector<std::string> object);
	void AddMinionAreas(vector<std::string> object);
	void AddLaunchPad(vector<std::string> object);
	void BuildTextures(vector<std::string> object);
	void DataDrivenMap::CheckTextID(int textID);
	void AddTexture(uint ID, std::string name);
	void LoadMapName();
	inline void CoruptedFile(uint errorNumber, uint errorLine){ GUIsystem::Instance()->MapProblem(errorNumber, errorLine); }

public:
	//--------------------------------------------------------------------------------------------//
	// Initialisation and Cleanup
	//--------------------------------------------------------------------------------------------//
	DataDrivenMap(const std::string& friendly_name, const std::string& mapName) :
		Map(friendly_name, mapName),
		mapName(mapName)
	{	}

	~DataDrivenMap() {

	}

	virtual void OnInitializeScene() override;
	virtual void SetSpawnLocations() override;
	virtual void AddObjects() override;

	inline void SetMapName(string name) { fileName = name; }

	//--------------------------------------------------------------------------------------------//
	// Special Object udpates (e.g. Pickups)
	//--------------------------------------------------------------------------------------------//
	virtual void OnUpdateScene(float dt) override;

	//--------------------------------------------------------------------------------------------//
	// Utility. TODO: can probably (re)move this
	//--------------------------------------------------------------------------------------------//
	void onButtonClicked();

};



















