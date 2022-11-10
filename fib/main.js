const path = require('path')
const fs = require('fs')

// 编译并实例化 wasm 模块，返回导出的接口
async function loadWebAssembly (filename, env) {
    const filePath = path.resolve(__dirname, filename)
  
    // 读入 wasm 文件的二进制代码
    const buffer = fs.readFileSync(filePath)
  
    // 将 wasm 包实例化并传入外部接口，因为没有外部依赖，不传 env 也可以的
    const results = await WebAssembly.instantiate(buffer, {
      env: Object.assign({
        '__memory_base': 0,
        '__table_base': 0,
        memory: new WebAssembly.Memory({ initial: 256, maximum: 256 }),
        table: new WebAssembly.Table({ initial: 0, maximum: 128, element: 'anyfunc' })
      }, env)
    })
  
    // 返回实例化好之后的接口
    if (results && results.instance) {
      return results.instance.exports
    }
  }


  loadWebAssembly('./out/fib-emcc.wasm').then(apis => {
    console.log(apis._fib(13))  // 输出 233
  })