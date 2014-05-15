#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface()
{
	testVar=0;
}




void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

	switch(key)
	{
		case 'j':
		{
			((LightingScene *) scene)->Robot->rotateLeft();
			break;
		}
            
        case 'l':
        {
            ((LightingScene *) scene)->Robot->rotateRight();
			break;
        }
            
        case 'i':
        {
            ((LightingScene *) scene)->Robot->moveForward();
			break;
        }
            
        case 'k':
        {
            ((LightingScene *) scene)->Robot->moveBackward();
			break;
        }
		case 'a':
		{
			// This is an example of accessing the associated scene
			// To test, create the function toggleSomething in your scene to activate/deactivate something
			((LightingScene *) scene)->toggleSomething();
			break;
		}
	}
}

void TPinterface::initGUI()
{
	/*
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel= addPanel("Group", 1);
	addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);
	
	// You could also pass a reference to a variable from the scene class, if public
	addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);
	*/

	 GLUI_Panel * lightsPanel = addPanel( (char*)"Luzes", 1);
    
    addCheckboxToPanel(lightsPanel, (char*)"Luz 1", &(((LightingScene*) scene)->light0On), 0);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 2", &(((LightingScene*) scene)->light1On), 1);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 3", &(((LightingScene*) scene)->light2On), 2);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 4", &(((LightingScene*) scene)->light3On), 3);
    addCheckboxToPanel(lightsPanel, (char*)"Luz 5", &(((LightingScene*) scene)->light4On), 4);
    
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	/*
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			printf ("New Val 1(interface): %d\n",testVar);
			break;
		};

		case 2:
		{
			printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			break;
		};
	};*/


	printf ("GUI control id: %ld\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
        case 0:
        {
            // value is the contrary because it has been switched already
            if ( !((LightingScene*) scene)->light0On)
                ((LightingScene*) scene)->light0->disable();
            else
                ((LightingScene*) scene)->light0->enable();

            break;
        }
		case 1:
		{
			if ( !((LightingScene*) scene)->light1On)
                ((LightingScene*) scene)->light1->disable();
			else
                ((LightingScene*) scene)->light1->enable();

            break;
		}
		case 2:
		{
			if ( !((LightingScene*) scene)->light2On)
                ((LightingScene*) scene)->light2->disable();
            else
                ((LightingScene*) scene)->light2->enable();
        
            break;
		}
        case 3:
        {
            if ( !((LightingScene*) scene)->light3On)
                ((LightingScene*) scene)->light3->disable();
            else
                ((LightingScene*) scene)->light3->enable();
            
            break;
        }
        case 4:
        {
            if ( !((LightingScene*) scene)->light4On)
                ((LightingScene*) scene)->light4->disable();
            else
                ((LightingScene*) scene)->light4->enable();
          
            break;
        }
            
	};
}

