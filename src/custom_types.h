#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

struct Bool
{
	Bool(): value(false) {}
	Bool(bool v): value(v) {}

	bool value;
	bool null = false;
};

struct Float
{
	Float(): value(0.0f) {}
	Float(float v): value(v) {}

	float value;
};

struct Int
{
	Int(): value(0) {}
	Int(int v): value(v) {}

	int value;
};

struct String
{
	String(): value("") {}
	String(const std::string& v): value(v) {}

	std::string value;
};

#endif