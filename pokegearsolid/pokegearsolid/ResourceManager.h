#pragma once

#include "Defines.h"
#include "DirectXFrame.h"
#include <vector>

#define maxtexture 20
#define maxModels 20
#define maxMat 10

enum type{
	null,
	texture,
	material,
	model
};


class ResourceManager{
private:
	TextureStruc textures[maxtexture];
	D3DMATERIAL9 materials[maxMat];
	D3Object Models[maxModels];
	int curTextures, curMat, curModels;

	DirectXFrame* dxManager;
	std::vector<resource> resources;
public:
	ResourceManager();
	ResourceManager(DirectXFrame* frame);
	void changeLoader(DirectXFrame* frame);
	void* loadFromFile(LPCWSTR name,type type);

	TextureStruc* getTexture(LPCWSTR name);
	D3DMATERIAL9* getMaterial(LPCWSTR name);
	D3Object* getModel(LPCWSTR name);

	void addMaterial(LPCWSTR name,D3DMATERIAL9 &mat);
	void addCube(LPCWSTR name,float height,float width, float depth,bool centered);

	bool setModMat(LPCWSTR modName,LPCWSTR matName);
	bool setModTex(LPCWSTR modName,LPCWSTR texName);

	int remove(LPCWSTR name,type type);
	void clear();
	~ResourceManager();
};