$input v_color0,v_texcoord0

#include <bgfx_shader.sh>
SAMPLER2D(s_tex,  0);

void main()
{
	//In this example the color component from the vertex shader is not used
	//gl_FragColor = v_color0;
	gl_FragColor = texture2D(s_tex,v_texcoord0);
}