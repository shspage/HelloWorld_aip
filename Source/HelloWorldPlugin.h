#ifndef __HelloWorldPlugin_h__
#define __HelloWorldPlugin_h__

#include "Plugin.hpp"
#include "HelloWorldID.h"

/**	Creates a new HelloWorldPlugin.
	@param pluginRef IN unique reference to this plugin.
	@return pointer to new HelloWorldPlugin.
*/
Plugin* AllocatePlugin(SPPluginRef pluginRef);

/**	Reloads the HelloWorldPlugin class state when the plugin is 
	reloaded by the application.
	@param plugin IN pointer to plugin being reloaded.
*/
void FixupReload(Plugin* plugin);

/**	Hooks HelloWorld up as an Illustrator plug-in.
	@ingroup HelloWorld
*/
class HelloWorldPlugin : public Plugin
{
public:
	/** Constructor.
		@param pluginRef IN reference to this plugin.
	*/
	HelloWorldPlugin(SPPluginRef pluginRef);

	/** Destructor.
	*/
	virtual ~HelloWorldPlugin();
  
  /**	Restores state of HelloWorldPlugin during reload.
	*/
	FIXUP_VTABLE_EX(HelloWorldPlugin, Plugin);
  
  /**	Initializes the plugin.
		@param message IN message sent by the plugin manager.
		@return kNoErr on success, other ASErr otherwise.
	*/
	ASErr StartupPlugin( SPInterfaceMessage * message );

	/**	Removes the plugin.
		@param message IN message sent by the plugin manager.
		@return kNoErr on success, other ASErr otherwise.
	*/
	ASErr ShutdownPlugin( SPInterfaceMessage * message );
    

   ASErr GoMenuItem(AIMenuMessage *message);
    
private:
    AIMenuItemHandle menuHandle1;
    
    AIErr addMenu(SPInterfaceMessage *message);
};

#endif
