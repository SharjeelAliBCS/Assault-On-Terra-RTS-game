#pragma once

#include "GameObject.h"
#include "EnemyObject.h"
#include "ProjectileObject.h"
#include "Particle.h"
#include <deque>


// Inherits from GameObject
class TowerObject : public GameObject {
public:
	TowerObject(glm::vec3 &entityPos, std::vector<GLuint> tex, std::vector<GLuint> explosion,GLint entityNumElements,float d,std::string type, float r, float ROF=1, int c=0);

	// Update function for moving the player object around
	virtual void update(double deltaTime) override;

	// Renders the GameObject using a shader
	virtual void  render(std::vector<Shader*> shaders) override;
	inline void setCurrEnemy(EnemyObject* enemy) {currentEnemy = enemy; }
	

	//getters
	//getter for the vector of objects
	inline std::vector<GLuint> getTexvec() { return texvec; }
	inline float getRange() {return range;}
	inline std::vector<GLuint> getExplosion_tex() { return explosion_tex; }
	GLuint getIcon() { return icon; }
	inline float getDamage() { return damage; }

	inline float getROF() { return curROF; }
	inline void setCurROF(float rof) { curROF = rof; }
	
	
private:
	float rotationSpeed;

	//*********Finite State Machine******
	enum State {
		Init,
		Idle,
		Locate,
		Fire,
		Death
	};

	State _state;
	
	void deathAnimation();
	void locateEnemy();
	void fireEnemy();
	//***********************************
	GLuint turretTexture;
	GLuint projectileTex;

	EnemyObject* currentEnemy;

	float curROF,defaultROF, frames;
	double lastShotTime;
	float damage;
	float range;
	GLint size;
	std::vector<ProjectileObject*> bullObjects;
	std::vector<GLuint> explosion_tex;
	GLuint icon;
	Particle* particle;
	std::vector<GLuint> texvec;
	std::vector<GLuint> texvecExplosion;

	



};