struct VS_INPUT
{
    float4 position : POSITION;   // CreateInputLayout()에서 사용했던 POSITION
    float4 color : COLOR;         // CreateInputLayout()에서 사용했던 COLOR
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

// 
VS_OUTPUT VS(VS_INPUT input)
{
    VS_OUTPUT output;
    output.position = input.position;
    output.color = input.color;
    
    return output;
}

float4 PS(VS_OUTPUT input) : SV_Target
{ 
    
    return float4(1,0,0,0);
}