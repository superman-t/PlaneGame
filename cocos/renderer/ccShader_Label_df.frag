const char* ccLabelDistanceFieldNormal_frag = R"(

#ifdef GL_ES
precision lowp float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec4 u_textColor;

void main()
{
    vec4 color = texture2D(CC_Texture0, v_texCoord);
    float dist = color.a;
    float width = 0.04;
    float alpha = smoothstep(0.5-width, 0.5+width, dist) * u_textColor.a;
    gl_FragColor = v_fragmentColor * vec4(u_textColor.rgb,alpha);
}
)";
