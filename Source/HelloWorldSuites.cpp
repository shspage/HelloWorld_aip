#include "IllustratorSDK.h"
#include "HelloWorldSuites.h"

// Suite externs
extern "C"
{
	SPBlocksSuite*			sSPBlocks = NULL;
    AIMenuSuite*            sAIMenu = NULL;
	AIUnicodeStringSuite*	sAIUnicodeString = NULL;
    AIShapeConstructionSuite* sAIShape = NULL;
}

// Import suites
ImportSuite gImportSuites[] = 
{
	kSPBlocksSuite, kSPBlocksSuiteVersion, &sSPBlocks,
    kAIMenuSuite, kAIMenuSuiteVersion, &sAIMenu,
	kAIUnicodeStringSuite, kAIUnicodeStringVersion, &sAIUnicodeString,
    kAIShapeConstructionSuite, kAIShapeConstructionSuiteVersion, &sAIShape,
	nullptr, 0, nullptr
};
