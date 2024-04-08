// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class XYTOR : ModuleRules
{
	public XYTOR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;


        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "AndroidRuntimeSettings" });
        PrivateDependencyModuleNames.AddRange(new string[] { "GenericGraphRuntime" });
        
        PublicIncludePaths.AddRange(new[]
        {
	        "XYTOR/Public/Core/Dialogues",
	        "XYTOR/Public/Core/Dialogues/Dev",
        });
    }
}
