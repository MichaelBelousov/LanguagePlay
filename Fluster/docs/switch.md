
# Need some sort of switch/case expression

```TypeScript
name = '@{first_name} @{'@{MI}. '}@{last_name}'
gpu_api = cond (platform == windows) => 'DirectX',
               (platform == mac)     => 'Metal',
               (platform == linux)   => 'Vulkan',
               (else)                => ''
```
