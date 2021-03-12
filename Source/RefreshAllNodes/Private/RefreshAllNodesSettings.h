#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/DeveloperSettings.h"
#include "RefreshAllNodesSettings.generated.h"

/**
 * Configure the Refresh All Nodes plug-in
 */
UCLASS(config=Engine, defaultconfig)
class URefreshAllNodesSettings : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
		URefreshAllNodesSettings();

#if WITH_EDITOR
		virtual FText GetSectionText() const override;
#endif

		/** Should the plugin refresh level blueprints? */
		UPROPERTY(config, EditAnywhere, Category=Search)
		bool RefreshLevelBlueprints;

		/** Should the plugin refresh blueprints in this project's game content folder? */
		UPROPERTY(config, EditAnywhere, Category=Search)
		bool RefreshGameBlueprints;

		/** Should the plugin refresh blueprints in the engine's content folder? */
		UPROPERTY(config, EditAnywhere, Category=Search)
		bool RefreshEngineBlueprints;

		/**
		 * Additional paths to search in for blueprints to refresh, good for plugins
		 * Example: Add "Paper2D" to the array to search the Paper2D plugin for blueprints to refresh.
		 */
		UPROPERTY(config, EditAnywhere, Category=Search)
		TArray<FName> AdditionalBlueprintPaths;
};
