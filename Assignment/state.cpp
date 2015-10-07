#include "state.h"

state::state(SDL_Renderer *renderer, stateManager *sM, imageManager *im)
{
	manageStates = sM;
	rdr = renderer;
	imgMan = im;
}

state::~state()
{

}






