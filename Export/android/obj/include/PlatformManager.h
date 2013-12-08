#ifndef INCLUDED_PlatformManager
#define INCLUDED_PlatformManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS0(Platform)
HX_DECLARE_CLASS0(PlatformManager)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  PlatformManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PlatformManager_obj OBJ_;
		PlatformManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< PlatformManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PlatformManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlatformManager"); }

		virtual Void returnPlatform( ::Platform platfrm);
		Dynamic returnPlatform_dyn();

		virtual ::Platform getPlatform( Float sHeight,Float sWidth);
		Dynamic getPlatform_dyn();

		::List platforms;
		static ::PlatformManager _instance;
		static ::PlatformManager instance( );
		static Dynamic instance_dyn();

};


#endif /* INCLUDED_PlatformManager */ 
