#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif
namespace sys{
namespace io{

Void FileOutput_obj::__construct(Dynamic f)
{
HX_STACK_PUSH("FileOutput::new","C:\\haxe\\haxe/std/cpp/_std/sys/io/FileOutput.hx",30);
{
	HX_STACK_LINE(30)
	this->__f = f;
}
;
	return null();
}

FileOutput_obj::~FileOutput_obj() { }

Dynamic FileOutput_obj::__CreateEmpty() { return  new FileOutput_obj; }
hx::ObjectPtr< FileOutput_obj > FileOutput_obj::__new(Dynamic f)
{  hx::ObjectPtr< FileOutput_obj > result = new FileOutput_obj();
	result->__construct(f);
	return result;}

Dynamic FileOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileOutput_obj > result = new FileOutput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FileOutput_obj::close( ){
{
		HX_STACK_PUSH("FileOutput::close","C:\\haxe\\haxe/std/cpp/_std/sys/io/FileOutput.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_LINE(47)
		this->super::close();
		HX_STACK_LINE(48)
		::sys::io::FileOutput_obj::file_close(this->__f);
	}
return null();
}


int FileOutput_obj::writeBytes( ::haxe::io::Bytes s,int p,int l){
	HX_STACK_PUSH("FileOutput::writeBytes","C:\\haxe\\haxe/std/cpp/_std/sys/io/FileOutput.hx",38);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(p,"p");
	HX_STACK_ARG(l,"l");
	struct _Function_1_1{
		inline static int Block( ::sys::io::FileOutput_obj *__this,::haxe::io::Bytes &s,int &p,int &l){
			HX_STACK_PUSH("*::closure","C:\\haxe\\haxe/std/cpp/_std/sys/io/FileOutput.hx",39);
			{
				HX_STACK_LINE(39)
				try{
					HX_STACK_LINE(39)
					return ::sys::io::FileOutput_obj::file_write(__this->__f,s->b,p,l);
				}
				catch(Dynamic __e){
					{
						HX_STACK_BEGIN_CATCH
						Dynamic e = __e;{
							HX_STACK_LINE(39)
							return hx::Throw (::haxe::io::Error_obj::Custom(e));
						}
					}
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(38)
	return _Function_1_1::Block(this,s,p,l);
}


Void FileOutput_obj::writeByte( int c){
{
		HX_STACK_PUSH("FileOutput::writeByte","C:\\haxe\\haxe/std/cpp/_std/sys/io/FileOutput.hx",34);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(34)
		try{
			HX_STACK_LINE(35)
			::sys::io::FileOutput_obj::file_write_char(this->__f,c);
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(35)
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
return null();
}


Dynamic FileOutput_obj::file_close;

Dynamic FileOutput_obj::file_write;

Dynamic FileOutput_obj::file_write_char;


FileOutput_obj::FileOutput_obj()
{
}

void FileOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileOutput);
	HX_MARK_MEMBER_NAME(__f,"__f");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FileOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__f,"__f");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FileOutput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { return __f; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { return file_close; }
		if (HX_FIELD_EQ(inName,"file_write") ) { return file_write; }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"file_write_char") ) { return file_write_char; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { __f=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { file_close=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_write") ) { file_write=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"file_write_char") ) { file_write_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__f"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("file_close"),
	HX_CSTRING("file_write"),
	HX_CSTRING("file_write_char"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("close"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("__f"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileOutput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_close,"file_close");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_write,"file_write");
	HX_MARK_MEMBER_NAME(FileOutput_obj::file_write_char,"file_write_char");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileOutput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_close,"file_close");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_write,"file_write");
	HX_VISIT_MEMBER_NAME(FileOutput_obj::file_write_char,"file_write_char");
};

Class FileOutput_obj::__mClass;

void FileOutput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.FileOutput"), hx::TCanCast< FileOutput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileOutput_obj::__boot()
{
	file_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_close"),(int)1);
	file_write= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_write"),(int)4);
	file_write_char= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_write_char"),(int)2);
}

} // end namespace sys
} // end namespace io
