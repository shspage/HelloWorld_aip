#include "IllustratorSDK.h"
#include "HelloWorldPlugin.h"
#include "HelloWorldSuites.h"
#include "SDKErrors.h"

#ifndef CHKERR
#define CHKERR aisdk::check_ai_error(error)
#endif

#ifdef MAC_ENV
const static AICharacterEncoding MY_MSG_ENC = kAIUTF8CharacterEncoding;
#else
// const static AICharacterEncoding MY_MSG_ENC = kAIPlatformCharacterEncoding;
const static AICharacterEncoding MY_MSG_ENC = kAIUTF8CharacterEncoding;
#endif

Plugin* AllocatePlugin(SPPluginRef pluginRef)
{
	return new HelloWorldPlugin(pluginRef);
}

void FixupReload(Plugin* plugin)
{
	HelloWorldPlugin::FixupVTable((HelloWorldPlugin*) plugin);
}

HelloWorldPlugin::HelloWorldPlugin(SPPluginRef pluginRef) :
	Plugin(pluginRef), menuHandle1(NULL)
{
	strncpy(fPluginName, kHelloWorldPluginName, kMaxStringLength);
}

HelloWorldPlugin::~HelloWorldPlugin()
{
}

ASErr HelloWorldPlugin::StartupPlugin( SPInterfaceMessage *message )
{
	ASErr error = kNoErr;
    error = Plugin::StartupPlugin(message); CHKERR;
	//sAIUser->MessageAlert(ai::UnicodeString("Hello from HelloWorld!"));
    error = this->addMenu(message); CHKERR;
    
	return error;
}

ASErr HelloWorldPlugin::ShutdownPlugin( SPInterfaceMessage *message )
{
	ASErr error = kNoErr;
	//sAIUser->MessageAlert(ai::UnicodeString("Goodbye from HelloWorld!"));
	error = Plugin::ShutdownPlugin(message);
	return error;
}

AIErr HelloWorldPlugin::addMenu(SPInterfaceMessage *message){
    AIErr error = kNoErr;
    AIPlatformAddMenuItemDataUS data;
    data.groupName = kWindowUtilsMenuGroup;
    data.itemText = ai::UnicodeString("SDKテスト", MY_MSG_ENC);
    error = sAIMenu->AddMenuItem(message->d.self, "HelloWorldMenu1",
                                 &data, 0, &menuHandle1); CHKERR;
        
    return error;
}

ASErr HelloWorldPlugin::GoMenuItem(AIMenuMessage *message){
    ASErr error = kNoErr;
    
    AIArtHandle rectangle1;
    error = sAIShape->NewRect(-50, 50, -150, 150, false, &rectangle1);
    CHKERR;
    
    AIArtHandle circle1;
    error = sAIShape->NewInscribedCenteredOval(200, -100, 100, 100, false, &circle1);
    
    return error;
}


