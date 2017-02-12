#ifndef STATE_h
#define STATE_h

class State
{
protected:
	int stateValue;
public:
	int getStateValue() const;
	virtual void displayAction(){}
	virtual ~State(){}
};

class MenuState : public State
{
public:
	MenuState();
	void displayAction() override;
};

class GameState : public State
{
public:
	GameState();
	void displayAction() override;
};

class Context
{
	State* currentState;
public:
	Context(State* state);
	int getStateValue() const;
	void setCurrentState(State* state);
	void displayAction() const;
};

extern Context myContext;
extern MenuState myMenuState;
extern GameState myGameState;

#endif // STATE_h
