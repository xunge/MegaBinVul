typedef struct lua_State lua_State;
typedef struct luaL_Reg {
  const char *name;
  int (*func)(lua_State *L);
} luaL_Reg;

extern int auxiliar_newclass(lua_State *L, const char *classname, const luaL_Reg *funcs);
extern const luaL_Reg x509_funcs[];
extern const luaL_Reg R[];
extern void openssl_register_xname(lua_State *L);
extern void openssl_register_xattribute(lua_State *L);
extern void openssl_register_xextension(lua_State *L);
extern void openssl_register_xstore(lua_State *L);
extern void openssl_register_xalgor(lua_State *L);
extern int luaopen_x509_req(lua_State *L);
extern int luaopen_x509_crl(lua_State *L);

#define MYVERSION "1.0"