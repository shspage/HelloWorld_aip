1. Copy the "Template" project from <SDK_root>/samplecode/Templates/Mac into your SampleCode
folder.
2. Open the Xcode Project inside your newly copied project.
3. Use the Find command to find all instances of "HelloWorld" and replace all instances with the
name of your project.
4. Rename all of the source files from "Template*.*" to "project_name*.*"
For example, rename TemplatePlugin.cpp to MyProjectPlugin.cpp.
5. In the folders pane, expand the Targets item. Rename the "Template" bundle in that section to the
name of your project (right-click "Templates" and choose Rename).
6. Double-click the project in the folders pane, then select the Build tab. Use the search box to find the
string "Template", in order to narrow down the build options. Look for "Product Name" under the
"Packaging" item and "PROJECTNAME" under the User-defined item. In both of these, change the
value from "Template" to the name of your project.
7. Build and run Illustrator to see your working project.