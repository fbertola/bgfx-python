
#include <map>
#include <memory>
#include <stdexcept>
#include <functional>
#include <string>

#include <pybind11/pybind11.h>

typedef std::function< pybind11::module & (std::string const &) > ModuleGetter;

void bind_bgfx(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_unknown_unknown(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_1(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_2(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_3(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_4(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_5(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_6(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_7(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_8(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_9(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_bgfx_10(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_platform(std::function< pybind11::module &(std::string const &namespace_) > &M);

void bind_imgui(std::function< pybind11::module &(std::string const &namespace_) > &M);
void bind_imgui_extra(std::function< pybind11::module &(std::string const &namespace_) > &M);

PYBIND11_MODULE(bgfx_lib, root_module) {
	root_module.doc() = "bgfx_python module";

	std::map <std::string, pybind11::module> modules;
	ModuleGetter M = [&](std::string const &namespace_) -> pybind11::module & {
		auto it = modules.find(namespace_);
		if( it == modules.end() ) throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ + " before it was created!!!");
		return it->second;
	};

	modules[""] = root_module;

	std::vector< std::pair<std::string, std::string> > sub_modules {
	    {"", "bgfx"},
		{"", "ImGui"},
		{"", "ImGuiExtra"},
	};
	for(auto &p : sub_modules ) modules[p.first.size() ? p.first+"::"+p.second : p.second] = modules[p.first].def_submodule(p.second.c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str() );

	//pybind11::class_<std::shared_ptr<void>>(M(""), "_encapsulated_data_");

	bind_bgfx(M);
	bind_unknown_unknown(M);
	bind_bgfx_1(M);
	bind_bgfx_2(M);
	bind_bgfx_3(M);
	bind_bgfx_4(M);
	bind_bgfx_5(M);
	bind_bgfx_6(M);
	bind_bgfx_7(M);
	bind_bgfx_8(M);
	bind_bgfx_9(M);
	bind_bgfx_10(M);
	bind_platform(M);

	bind_imgui(M);
    bind_imgui_extra(M);
}
