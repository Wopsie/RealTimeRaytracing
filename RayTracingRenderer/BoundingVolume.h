#pragma once
#include "Surface.h"
#include "Material.h"
#include "MathLibrary.h"
#include "Hitable.h"
#include <vector>

struct ShadingInfo;
class BoundingVolume : public Hitable
{
public:
	virtual const std::vector<Hitable*> GetVolumeContent() const = 0;

protected:
	std::vector<Hitable*> volumeContents = { nullptr };
};

