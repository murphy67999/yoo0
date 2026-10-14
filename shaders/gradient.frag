#version 330

out vec4 finalColor;

void main(){
    vec2 uv = gl_FragCoord.xy / vec2(1800, 1000);

    finalColor = vec4(0.0, uv.y, 0.0, 1.0);
}