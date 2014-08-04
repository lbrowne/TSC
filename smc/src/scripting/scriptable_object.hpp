#ifndef SMC_SCRIPTING_SCRIPTABLE_OBJECT_HPP
#define SMC_SCRIPTING_SCRIPTABLE_OBJECT_HPP
#include "../core/global_basic.hpp"

namespace SMC{
	namespace Scripting{

		/**
		 * This class encapsulates the stuff that is common
		 * to all objects exposed to the mruby scripting
		 * interface. That is, it holds the mruby event tables.
		 */
		class cScriptable_Object
		{
		public:
			cScriptable_Object();
			virtual ~cScriptable_Object();

			void clear_event_handlers();
			void register_event_handler(const string& evtname, mrb_value callback);
			vector<mrb_value>::iterator event_handlers_begin(const string& evtname);
			vector<mrb_value>::iterator event_handlers_end(const string& evtname);

		protected:
			/// Mapping of event names and registered callbacks.
			std::map<string, vector<mrb_value> > m_callbacks;
		};
	};
};
#endif
