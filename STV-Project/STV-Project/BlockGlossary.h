#pragma once

enum resource_id {
	RES_AIR = 2500, RES_UNKNOWN,
	RES_GRASS = 0, RES_DIRT, RES_STONE, RES_ORE, RES_SNOW, RES_BRICKS, RES_PLANKS, RES_THATCH
};

struct Resource
{
	resource_id resource;
	float density = 0;

	Resource() 
	{
		resource = RES_AIR;
	}

	Resource(resource_id resource) : resource(resource) {};
	
	void operator=(resource_id res)
	{
		resource = res;
		density = 0;
	}

	bool operator==(resource_id res)
	{
		return resource == res;
	}

	bool operator!=(resource_id res)
	{
		return resource != res;
	}
};

static bool IsSolid(Resource res)
{
	return !(res == RES_AIR);
}

static bool DoesBlend(Resource res)
{
	return !(res == RES_BRICKS || res == RES_PLANKS);
}

static float GetBlendDensity(Resource res) 
{
	switch (res.resource) 
	{
	case RES_BRICKS:
		return 0.5f;
	case RES_PLANKS:
		return 0.1f;
	default:
		return 0;
	}
}