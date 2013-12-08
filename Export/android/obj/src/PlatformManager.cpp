#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Platform
#include <Platform.h>
#endif
#ifndef INCLUDED_PlatformManager
#include <PlatformManager.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void PlatformManager_obj::__construct()
{
HX_STACK_PUSH("PlatformManager::new","PlatformManager.hx",26);
{
	HX_STACK_LINE(27)
	this->platforms = ::List_obj::__new();
	HX_STACK_LINE(28)
	{
		HX_STACK_LINE(28)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(28)
		while(((_g < (int)20))){
			HX_STACK_LINE(28)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(29)
			this->platforms->add(::Platform_obj::__new());
		}
	}
}
;
	return null();
}

PlatformManager_obj::~PlatformManager_obj() { }

Dynamic PlatformManager_obj::__CreateEmpty() { return  new PlatformManager_obj; }
hx::ObjectPtr< PlatformManager_obj > PlatformManager_obj::__new()
{  hx::ObjectPtr< PlatformManager_obj > result = new PlatformManager_obj();
	result->__construct();
	return result;}

Dynamic PlatformManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlatformManager_obj > result = new PlatformManager_obj();
	result->__construct();
	return result;}

Void PlatformManager_obj::returnPlatform( ::Platform platfrm){
{
		HX_STACK_PUSH("PlatformManager::returnPlatform","PlatformManager.hx",41);
		HX_STACK_THIS(this);
		HX_STACK_ARG(platfrm,"platfrm");
		HX_STACK_LINE(41)
		this->platforms->add(platfrm);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformManager_obj,returnPlatform,(void))

::Platform PlatformManager_obj::getPlatform( Float sHeight,Float sWidth){
	HX_STACK_PUSH("PlatformManager::getPlatform","PlatformManager.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sHeight,"sHeight");
	HX_STACK_ARG(sWidth,"sWidth");
	HX_STACK_LINE(35)
	::Platform pltfrm = this->platforms->pop();		HX_STACK_VAR(pltfrm,"pltfrm");
	HX_STACK_LINE(36)
	pltfrm->set_x((::Math_obj::random() * sWidth));
	HX_STACK_LINE(37)
	pltfrm->set_y((::Math_obj::random() * sHeight));
	HX_STACK_LINE(38)
	return pltfrm;
}


HX_DEFINE_DYNAMIC_FUNC2(PlatformManager_obj,getPlatform,return )

::PlatformManager PlatformManager_obj::_instance;

::PlatformManager PlatformManager_obj::instance( ){
	HX_STACK_PUSH("PlatformManager::instance","PlatformManager.hx",18);
	HX_STACK_LINE(18)
	if (((::PlatformManager_obj::_instance == null()))){
		HX_STACK_LINE(20)
		return ::PlatformManager_obj::_instance = ::PlatformManager_obj::__new();
	}
	else{
		HX_STACK_LINE(22)
		return ::PlatformManager_obj::_instance;
	}
	HX_STACK_LINE(18)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PlatformManager_obj,instance,return )


PlatformManager_obj::PlatformManager_obj()
{
}

void PlatformManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlatformManager);
	HX_MARK_MEMBER_NAME(platforms,"platforms");
	HX_MARK_END_CLASS();
}

void PlatformManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(platforms,"platforms");
}

Dynamic PlatformManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"instance") ) { return instance_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { return _instance; }
		if (HX_FIELD_EQ(inName,"platforms") ) { return platforms; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getPlatform") ) { return getPlatform_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"returnPlatform") ) { return returnPlatform_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlatformManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { _instance=inValue.Cast< ::PlatformManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"platforms") ) { platforms=inValue.Cast< ::List >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlatformManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("platforms"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_instance"),
	HX_CSTRING("instance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("returnPlatform"),
	HX_CSTRING("getPlatform"),
	HX_CSTRING("platforms"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlatformManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PlatformManager_obj::_instance,"_instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlatformManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PlatformManager_obj::_instance,"_instance");
};

Class PlatformManager_obj::__mClass;

void PlatformManager_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlatformManager"), hx::TCanCast< PlatformManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PlatformManager_obj::__boot()
{
}

