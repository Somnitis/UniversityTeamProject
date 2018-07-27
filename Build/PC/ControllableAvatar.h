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
 (* %.       #@%.(@@.        NIKOLAOS  FRAGKAS                   .#      
  (            #(@*			  Avatar    Class                   */
//							    5/ 02 / 2018



#pragma once
#include "Avatar.h"

enum Movement {
	NO_MOVE,
	MOVE_FORWARD,
	MOVE_BACKWARD,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_JUMP
};

class ControllableAvatar : public Avatar
{
private:

	float lifeDrainFactor;  //The lower the value the faster the movement based life drain is.

	Movement curMove;			//The current movement direction
	Movement previousMove;		//The previous movement direction

public:
	ControllableAvatar();
	ControllableAvatar(Vector3 pos, Colour c, uint id = 0, float s = 1.0f); //Build Player using starting possition Colour and size
	
	virtual void Update(float dt);

	void MovementState(Movement moveDir, float yaw, float dt); // handles the movement of the player.

	void ProcessAvatarInput(float time);		// Takes the keyboard input to control ball

	virtual bool PlayerCallbackFunction(PhysicsNode* self, PhysicsNode* collidingObject) override;
	
	~ControllableAvatar();

};

