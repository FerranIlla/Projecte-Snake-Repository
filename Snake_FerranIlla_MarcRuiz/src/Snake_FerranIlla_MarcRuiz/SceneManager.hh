#pragma once

#include "Scene.hh"
#include <vector>
#include <typeindex>
#include <unordered_map>
using namespace std;

#define SM SceneManager::Instance()

// SceneManager class to store and control the whole game scenes
class SceneManager {
private:
	// Array of screens
	vector<Scene> m_scenes;
	//pointer to the current scene --> 
	Scene *m_curScene{ nullptr };

public:
	//constructor
	inline static SceneManager &Instance() {
		static SceneManager sceneManager;
		return sceneManager;
	}
	//destructor
	~SceneManager() { 
		m_scenes.clear(); //does not dealloctae the memory
		m_curScene = nullptr;
	}
	
	void AddScene(Scene s) {
		m_scenes.push_back(s);
	}
 
	void SetCurScene(Scene s) {
		if (m_curScene != nullptr) {
			m_curScene->OnExit();
			m_curScene->SetState<SceneState::SLEEP>();
			*m_curScene = s;
			m_curScene->SetState<SceneState::RUNNING>();
			m_curScene->OnEntry();
		}
	}
	inline Scene *&GetCurScene(void) { return m_curScene; }
private:
	SceneManager() = default;
	SceneManager(const SceneManager &rhs) = delete;
	SceneManager &operator=(const SceneManager &rhs) = delete;


};