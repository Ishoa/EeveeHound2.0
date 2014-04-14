#include "ResourceManager.h"

ResourceManager::ResourceManager(){
	//set counts to 0
	curTextures = 0;
	curMat = 0;
	curModels = 0;

	//set all pointers to null
	for(int i = 0;i<maxModels;++i)
	{
		Models[i].obj = 0;
	}
	for(int i = 0;i<maxtexture;++i)
	{
		textures[i].objTex = 0;
	}
}

ResourceManager::ResourceManager(DirectXFrame* frame){
	dxManager = frame;
	//set counts to 0
	curTextures = 0;
	curMat = 0;
	curModels = 0;

	//set all pointers to null
	for(int i = 0;i<maxModels;++i)
	{
		Models[i].obj = 0;
	}
	for(int i = 0;i<maxtexture;++i)
	{
		textures[i].objTex = 0;
	}
}

void ResourceManager::changeLoader(DirectXFrame* frame){
	dxManager = frame;
}

void* ResourceManager::loadFromFile(LPCWSTR name,type t){
	switch(t){
	case texture:
		return getTexture(name);
			
	}
}

int ResourceManager::remove(LPCWSTR name,type t){
	return 0;
}

TextureStruc* ResourceManager::getTexture(LPCWSTR name){
	//get resource manager size
	int res = resources.size();
	//look for a texture with the name
	for(int i = 0;i<res;++i){
		//if the res is a texture and has the same name return it
		if(resources[i].type == texture && resources[i].name == name){
			return (TextureStruc*)resources[i].res;
		}
	}
	//create a resource incase we need to add one
	resource reso;
	//if no matching texture is found and we can still load more load it else return 0
	if(curTextures<maxtexture){
		//load the texture
		dxManager->LoadTex(name,0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[curTextures].texInfo,0,&textures[curTextures].objTex);
		//rember the count
		res = curTextures;
		//increment the total count
		++curTextures;
		//set resource info
		reso.name = name;
		reso.res = &textures[res];
		reso.type = texture;
		//add resource to the vector
		resources.push_back(reso);
		//return the loaded texture
		return (TextureStruc*)resources[res].res;
	}
	else
		return 0;
}

void ResourceManager::clear(){
	for(int i = 0;i<maxModels;++i)
	{
		if(Models[i].obj != 0)
		{
			Models[i].objDec->Release();
			Models[i].objDec = 0;
			Models[i].objInd->Release();
			Models[i].objInd = 0;
			Models[i].obj->Release();
			Models[i].obj = 0;
		}
	}
	for(int i = 0;i<maxtexture;++i)
	{
		if(textures[i].objTex!=0)
		{
			textures[i].objTex->Release();
			textures[i].objTex = 0;
		}
	}
}

ResourceManager::~ResourceManager(){
	clear();
}