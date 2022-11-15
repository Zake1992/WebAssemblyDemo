使用 WebAssembly.compile 来写胶水代码，目前代码还没有调通，报错如下

```
Uncaught (in promise) LinkError: import object field '__stack_pointer' is not a Number
    loadWebAssembly http://127.0.0.1:5500/multiply/test.html:25
    promise callback*loadWebAssembly http://127.0.0.1:5500/multiply/test.html:9
    <anonymous> http://127.0.0.1:5500/multiply/test.html:29
```