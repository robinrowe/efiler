/*
 * $Id$
 *
 * EFiler - EDE File Manager
 * Part of Equinox Desktop Environment (EDE).
 * Copyright (c) 2000-2007 EDE Authors.
 *
 * This program is licenced under terms of the
 * GNU General Public Licence version 2 or newer.
 * See COPYING for details.
 */


// File properties window


#ifndef _Properties_h_
#define _Properties_h_

//#include <edelib/Window.h>
//#include <edelib/MimeType.h>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <string>

namespace edelib
{	typedef Fl_Window Window;
	static const unsigned ICON_SIZE_TINY = 5;
	static const unsigned ICON_SIZE_SMALL = 10;
	static const unsigned ICON_SIZE_MEDIUM = 20;
	static const unsigned ICON_SIZE_LARGE = 25;
	static const unsigned ICON_SIZE_HUGE = 30;
	static const unsigned ICON_SIZE_ENORMOUS = 40;
	static const unsigned DW_REPORT_NONE = 0;
	static const unsigned DW_REPORT_DELETE = 1;
	static const bool FILE_TEST_IS_EXECUTABLE = false;
	static const unsigned DW_NONE = 0;
	static const unsigned ICON_CONTEXT_MIMETYPE = 7;

	inline
	void str_tolower(unsigned char* s)
	{	while(*s)
		{	*s=tolower(*s);
			s++;
	}	}
	
	inline
	std::string& dir_home()
	{	static std::string s;
		return s;
	}

	inline
	std::string& dir_current()
	{	static std::string s;
		return s;
	}

	inline
	void alert(const char* form,const char* data)
	{	printf(form,data);
	}

	inline
	int run_async(const char*,const char*)
	{	return 0;
	}

	inline
	int run_async(const char*,const char*,const char*)
	{	return 0;
	}

	inline
	int run_sync(const char*,const char*)
	{	return 0;
	}

	class IconLoader
	{	static std::string path;
	public:
		IconLoader()
		{	path = "Error";
		}
		static const std::string& get_path(const char* icon_name,unsigned)
		{	return path;
		}
		static const std::string& get_path(const char* icon_name,unsigned,unsigned)
		{	return path;
		}
		static bool inited()
		{	return true;
		}
	};
	
	class MimeType
	{	std::string path;
	public:
		MimeType()
		{	path = "Error";
		}
		void set(const char* fullpath)
		{	//path = fullpath;
		}
		const std::string& icon_name() const
		{	return path;
		}
		const std::string& comment() const
		{	return path;
		}
		std::string& type()
		{	return path;
		}
	};

	class Resource
	{	std::string path;
	public:
		void set(const char*,const char*,bool)
		{}
		void save(const char*)
		{}
	};

	class DirWatch
	{public:
		static void init()
		{}
		typedef void DW_cb(const char* dir, const char* what_changed, int flags, void* d);
		static void callback(DW_cb)
		{}
		static unsigned notifier()
		{	return 0;
		}
		static void shutdown()
		{}
	};

	inline
	bool file_exists(const char*)
	{	return true;
	}

	inline
	bool dir_exists(const char*)
	{	return true;
	}

	inline
	bool file_readable(const char*)
	{	return true;
	}

	inline
	bool file_writeable(const char*)
	{	return true;
	}

	inline
	bool dir_writeable(const char*)
	{	return true;
	}

	inline
	bool file_remove(const char*)
	{	return true;
	}

	inline
	bool dir_remove(const char*)
	{	return true;
	}

	inline
	bool file_rename(const char*,const char*)
	{	return true;
	}
}

extern edelib::MimeType mime_resolver;
extern edelib::Resource app_config;

inline
bool file_test(const char*,unsigned)
{	return true;
}

inline
int ede_choice_alert(const char* msg, const char* button1,const char* button2,int)
{//	typedef fl_alert MessageBox; //fl_alert("%s: %s", filename, strerror(errno)); 
	return 0;
}

inline
int ede_choice_alert(const char* msg, const char* button1,const char* button2,const char* button3, int)
{//	typedef fl_alert MessageBox; //fl_alert("%s: %s", filename, strerror(errno)); 
	return 0;
}

inline
int ede_choice_alert(const char* msg, const char* button1,const char* button2,const char* button3,const char* button4, int)
{//	typedef fl_alert MessageBox; //fl_alert("%s: %s", filename, strerror(errno)); 
	return 0;
}

#define ede_strverscmp strcmp
#define strverscmp strcmp
#define EDEBUG //

inline
const char* _(const char* s)
{	return s;
}

class Properties : public edelib::Window {
private:
	const char* _file;

	// We need our own MIME resolver
	edelib::MimeType mime_resolver;

public:
	// Construct window
	Properties(const char* file);

	// This function is friend of Properties because it needs to access
	// values of various widgets
	friend void properties_ok_cb(Fl_Widget*w, void*i);

};

#endif
