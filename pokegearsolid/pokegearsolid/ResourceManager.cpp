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

D3Object* ResourceManager::getModel(LPCWSTR name){
	//get resource manager size
	int res = resources.size();
	//look for a model with the name
	for(int i = 0;i<res;++i){
		//if the res is a model and has the same name return it
		if(resources[i].type == model && resources[i].name == name){
			return (D3Object*)resources[i].res;
		}
	}
	//if none return null
	return 0;
}

D3DMATERIAL9* ResourceManager::getMaterial(LPCWSTR name){
	//get resource manager size
	int res = resources.size();
	//look for a material with the name
	for(int i = 0;i<res;++i){
		//if the res is a material and has the same name return it
		if(resources[i].type == material && resources[i].name == name){
			return (D3DMATERIAL9*)resources[i].res;
		}
	}
	//if none return null
	return 0;
}

void ResourceManager::addMaterial(LPCWSTR name,D3DMATERIAL9 &mat){
	//create a resource so we can add one
	resource reso;
	//set res name
	reso.name = name;
	//set type to material
	reso.type = material;
	//copy material
	materials[curMat].Ambient = mat.Ambient;
	materials[curMat].Diffuse = mat.Diffuse;
	materials[curMat].Emissive = mat.Emissive;
	materials[curMat].Power = mat.Power;
	materials[curMat].Specular = mat.Specular;
	//set res resource
	reso.res = &materials[curMat];
	//add res to resource list
	resources.push_back(reso);
	//increment mat count
	++curMat;
}

void ResourceManager::addCube(LPCWSTR name,float height,float width, float depth,bool cen){
	//create a resource so we can add one
	resource reso;
	//set res name
	reso.name = name;
	//set res type to model
	reso.type = model;
	//create cube
	if(cen) {
		dxManager->CreateUVCube(Models[curModels],height,width,depth);
	}
	else {
		dxManager->CreateUncenteredCube(Models[curModels],height,width,depth);
	}
	//set res' resource
	reso.res = &Models[curModels];
	//increment model count
	++curModels;
	//add res to res list
	resources.push_back(reso);
}

//set a models material and returns true if failed
bool ResourceManager::setModMat(LPCWSTR modName,LPCWSTR matName){
	//rember resources
	resource * mod, * mat;
	//set pointers to null
	mod = 0;
	mat = 0;
	//get resource manager size
	int res = resources.size();
	//look for a model with the name
	for(int i = 0;i<res;++i){
		//if the res is a model and has the same name return it
		if(resources[i].type == model && resources[i].name == modName){
			mod = &resources[i];
			break;
		}
	}
	//look for a material with the name
	for(int i = 0;i<res;++i){
		//if the res is a material and has the same name return it
		if(resources[i].type == material && resources[i].name == matName){
			mat = &resources[i];
			break;
		}
	}
	//if mod or mat in null return an error
	if(!mod||!mat){
		return true;
	}
	//set model mat
	((D3Object*)mod->res)->objMat = (D3DMATERIAL9*)mat->res;
	return false;
}

bool ResourceManager::setModTex(LPCWSTR modName,LPCWSTR texName){
	//rember resources
	resource * mod, * tex;
	//set pointers to null
	mod = 0;
	tex = 0;
	//get resource manager size
	int res = resources.size();
	//look for a model with the name
	for(int i = 0;i<res;++i){
		//if the res is a model and has the same name return it
		if(resources[i].type == model && resources[i].name == modName){
			mod = &resources[i];
			break;
		}
	}
	//look for a texture with the name
	for(int i = 0;i<res;++i){
		//if the res is a texture and has the same name return it
		if(resources[i].type == texture && resources[i].name == texName){
			tex = &resources[i];
			break;
		}
	}
	//if mod or tex in null return an error
	if(!mod||!tex){
		return true;
	}
	//set model tex
	((D3Object*)mod->res)->objTex = ((TextureStruc*)tex->res)->objTex;
	return false;
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