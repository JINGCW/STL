#ifndef STANDARD_TEMPLATE_LIBRARIES_C_CONFIG_H
#define STANDARD_TEMPLATE_LIBRARIES_C_CONFIG_H

#ifdef WIN32
#   ifdef DLL_EXPORTS
#       define EXPORT_API __declspec(dllexport)
#   else
#       define EXPORT_API __declspec(dllimport)
#   endif//DLL_EXPORTS
#else
#define EXPORT_API
#endif//WIN32


#endif //STANDARD_TEMPLATE_LIBRARIES_C_CONFIG_H
