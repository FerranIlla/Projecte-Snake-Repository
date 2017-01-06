#pragma once

// Enum state fot each Scene in the Game
enum class SceneState {
	NONE,		// Default empty state
	RUNNING,	// State of updating the current screen
	EXIT,		// State of leaving the current game
	SLEEP		// State of leaving scene stand by
};

// Scene class that serves as part of the Model
class Scene {
	friend class SceneManager;
public:
	explicit Scene() = default;
	virtual ~Scene() = default;

	//TODO
	// Called when entering into a new scene
	void OnEntry(void) {
		
	};
	// Called when leaving from a scene
	void OnExit(void) {
	
	};
	// Main update scene function called in game loop
	void Update(void) {
	
	};
	// Main draw scene function called in game loop
	void Draw(void) {
	
	};
	// State methods
	template <SceneState state> inline void SetState(void) { currentState = state; };
	inline SceneState GetState(void) const { return currentState; };
	template <SceneState state> inline bool CheckState(void) const { return currentState == state; };
protected:
	SceneState currentState{ SceneState::NONE }; // Current state of the scene, NONE by default
};