// Copyright Bismuth Consultancy BV. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FBismuthConsultancyModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
