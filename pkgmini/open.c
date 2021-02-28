#include "pkgd.h"

FILE *fptr;
long length;
char *data = 0;

char *openfile(){
fptr = fopen(FILENAME, "rb");
if(fptr){
  fseek(fptr, 0, SEEK_END);
  length = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  data = malloc(length);
  if(data)
  {
    fread(data, 1, length, fptr);
  }
  fclose(fptr);
}

if(data){
  

  //printf("%s", ver);
}
return data;
}

// remove tokken from string str, tokken
void rmtok(char *X, char *Y) {
  char *m;
  int len = strlen(Y);
  while ((m = strstr(X, Y))) {
    *m = '\0';
    strcat(X, m+len);
    }
}

// replace one string at a time src, str, new
void rplstr(char *X, char *Y, char *Z){
     char *q;
     if ((q = strstr(X, Y)) == NULL) {
         return;
     }
     int y_len = strlen(Y);
     int z_len = strlen(Z);
     int t_len = strlen(q+y_len);
     memmove(q+z_len,q+y_len,t_len+1);
     memcpy(q, Z, z_len);
}

// replace all src, str, new
void strmagic(char *X, char *Y, char *Z){
char *w = strstr(X, Y);
  if(w){
  int len = strlen(X)+strlen(Z)-strlen(Y);
  char r[len];
  memset(r, 0, len);
    if(w >= X){
    strncpy(r, X, w-X);
    r[w-X]='\0';
    strncat(r, Z, strlen(Z));
    strncat(r, w+strlen(Y), w+strlen(Y)-X+strlen(X));
    strcpy(X, r);
    strmagic(w+strlen(Z), Y, Z);
    }
  }
}

char *pkg(){
char *pkg = strstr(data, PKG);
  if(!pkg){
  return strdup("");
  } else {
  strtok(pkg, "\n");
  rmtok(pkg, PKG);
  }
return pkg;
}

char *ver(){
char *ver = strstr(data, VER);
  if(!ver){
  return strdup("");
  } else {
  strtok(ver, "\n");
  rmtok(ver, VER);
  }
return ver;
}

char *rel(){
char *rel = strstr(data, REL);
  if(!rel){
  return strdup("");
  } else {
  strtok(rel, "\n");
  rmtok(rel, REL);
  }
return rel;
}

char *epc(){
char *epc = strstr(data, EPC);
  if(!epc){
  return strdup("");
  } else {
  strtok(epc, "\n");
  rmtok(epc, EPC);
  }
return epc;
}

char *dsc(){
char *dsc = strstr(data, DSC);
  if(!dsc){
  return strdup("");
  } else {
  strtok(dsc, "\n");
  rmtok(dsc, DSC);
  rmtok(dsc, "'");
  }
return dsc;
}

char *ark(){
char *ark = strstr(data, ARK);
  if(!ark){
  return strdup("");
  } else {
  strtok(ark, "\n");
  rmtok(ark, ARK);
  rmtok(ark, "'");
  rmtok(ark, "(");
  rmtok(ark, ")");
  }
return ark;
}

char *url(){
char *url = strstr(data, URL);
  if(!url){
  return strdup("");
  } else {
  strtok(url, "\n");
  rmtok(url, URL);
  rmtok(url, "'");
  rmtok(url, "\"");
  rmtok(url, "(");
  rmtok(url, ")");
  }
return url;
}

char *lic(){
char *lic = strstr(data, LIC);
  if(!lic){
  return strdup("");
  } else {
  strtok(lic, "\n");
  rmtok(lic, LIC);
  rmtok(lic, "'");
  rmtok(lic, "\"");
  rmtok(lic, "(");
  rmtok(lic, ")");
  }
return lic;
}

char *grp(){
char *grp = strstr(data, GRP);
  if(!grp){
  return strdup("");
  } else {
  strtok(grp, "\n");
  rmtok(grp, GRP);
  rmtok(grp, "'");
  rmtok(grp, "\"");
  rmtok(grp, "(");
  rmtok(grp, ")");
  }
return grp;
}

char *dep(){
char *dep = strstr(data, DEP);
  if(!dep){
  return strdup("");
  } else {
  strtok(dep, "\n");
  rmtok(dep, DEP);
  rmtok(dep, "'");
  rmtok(dep, "\"");
  rmtok(dep, "(");
  rmtok(dep, ")");
  }
return dep;
}

char *odp(){
char *odp = strstr(data, ODP);
  if(!odp){
  return strdup("");
  } else {
  strtok(odp, "\n");
  rmtok(odp, ODP);
  rmtok(odp, "'");
  rmtok(odp, "\"");
  rmtok(odp, "(");
  rmtok(odp, ")");
  }
return odp;
}

char *mdp(){
char *mdp = strstr(data, MDP);
  if(!mdp){
  return strdup("");
  } else {
  strtok(mdp, "\n");
  rmtok(mdp, MDP);
  rmtok(mdp, "'");
  rmtok(mdp, "\"");
  rmtok(mdp, "(");
  rmtok(mdp, ")");
  }
return mdp;
}

char *cdp(){
char *cdp = strstr(data, CDP);
  if(!cdp){
  return strdup("");
  } else {
  strtok(cdp, "\n");
  rmtok(cdp, CDP);
  rmtok(cdp, "'");
  rmtok(cdp, "\"");
  rmtok(cdp, "(");
  rmtok(cdp, ")");
  }
return cdp;
}

char *prv(){
char *prv = strstr(data, PRV);
  if(!prv){
  return strdup("");
  } else {
  strtok(prv, "\n");
  rmtok(prv, PRV);
  rmtok(prv, "'");
  rmtok(prv, "\"");
  rmtok(prv, "(");
  rmtok(prv, ")");
  }
return prv;
}

char *con(){
char *con = strstr(data, CON);
  if(!con){
  return strdup("");
  } else {
  strtok(con, "\n");
  rmtok(con, CON);
  rmtok(con, "'");
  rmtok(con, "\"");
  rmtok(con, "(");
  rmtok(con, ")");
  }
return con;
}

char *rpl(){
char *rpl = strstr(data, RPL);
  if(!rpl){
  return strdup("");
  } else {
  strtok(rpl, "\n");
  rmtok(rpl, RPL);
  rmtok(rpl, "'");
  rmtok(rpl, "\"");
  rmtok(rpl, "(");
  rmtok(rpl, ")");
  }
return rpl;
}

char *bac(){
char *bac = strstr(data, BAC);
  if(!bac){
  return strdup("");
  } else {
  strtok(bac, "\n");
  rmtok(bac, BAC);
  rmtok(bac, "'");
  rmtok(bac, "\"");
  rmtok(bac, "(");
  rmtok(bac, ")");
  }
return bac;
}

char *opt(){
char *opt = strstr(data, OPT);
  if(!opt){
  return strdup("");
  } else {
  strtok(opt, "\n");
  rmtok(opt, OPT);
  rmtok(opt, "'");
  rmtok(opt, "\"");
  rmtok(opt, "(");
  rmtok(opt, ")");
  }
return opt;
}

char *ins(){
char *ins = strstr(data, INS);
  if(!ins){
  return strdup("");
  } else {
  strtok(ins, "\n");
  rmtok(ins, INS);
  rmtok(ins, "'");
  rmtok(ins, "\"");
  rmtok(ins, "(");
  rmtok(ins, ")");
  }
return ins;
}

char *chg(){
char *chg = strstr(data, CHG);
  if(!chg){
  return strdup("");
  } else {
  strtok(chg, "\n");
  rmtok(chg, CHG);
  rmtok(chg, "'");
  rmtok(chg, "\"");
  rmtok(chg, "(");
  rmtok(chg, ")");
  }
return chg;
}

char *src(){
char *src = strstr(data, SRC);
  if(!src){
  return strdup("");
  } else {
  strtok(src, "\n");
  rmtok(src, SRC);
  rmtok(src, "'");
  rmtok(src, "\"");
  rmtok(src, "(");
  rmtok(src, ")");
  rmtok(src, "{");
  rmtok(src, "}");
  rmtok(src, ",.asc");
  rplstr(src, "$pkgname-$pkgver", pkg());
  }
return src;
}

char *nex(){
char *nex = strstr(data, NEX);
  if(!nex){
  return strdup("");
  } else {
  strtok(nex, "\n");
  rmtok(nex, NEX);
  rmtok(nex, "'");
  rmtok(nex, "\"");
  rmtok(nex, "(");
  rmtok(nex, ")");
  }
return nex;
}

char *vpg(){
char *vpg = strstr(data, VPG);
  if(!vpg){
  return strdup("");
  } else {
  strtok(vpg, "\n");
  rmtok(vpg, VPG);
  rmtok(vpg, "'");
  rmtok(vpg, "\"");
  rmtok(vpg, "(");
  rmtok(vpg, ")");
  }
return vpg;
}

char *md5(){
char *md5 = strstr(data, MD5);
  if(!md5){
  return strdup("");
  } else {
  strtok(md5, "\n");
  rmtok(md5, MD5);
  rmtok(md5, "'");
  rmtok(md5, "\"");
  rmtok(md5, "(");
  rmtok(md5, ")");
  }
return md5;
}

char *sh1(){
char *sh1 = strstr(data, SH1);
  if(!sh1){
  return strdup("");
  } else {
  strtok(sh1, "\n");
  rmtok(sh1, SH1);
  rmtok(sh1, "'");
  rmtok(sh1, "\"");
  rmtok(sh1, "(");
  rmtok(sh1, ")");
  }
return sh1;
}

char *sh2(){
char *sh2 = strstr(data, SH2);
  if(!sh2){
  return strdup("");
  } else {
  strtok(sh2, "\n");
  rmtok(sh2, SH2);
  rmtok(sh2, "'");
  rmtok(sh2, "\"");
  rmtok(sh2, "(");
  rmtok(sh2, ")");
  }
return sh2;
}

char *sh5(){
char *sh5 = strstr(data, SH5);
  if(!sh5){
  return strdup("");
  } else {
  strtok(sh5, "\n");
  rmtok(sh5, SH5);
  rmtok(sh5, "'");
  rmtok(sh5, "\"");
  rmtok(sh5, "(");
  rmtok(sh5, ")");
  }
return sh5;
}

int main(void){
//openfile();
char *a = openfile();
rplstr(a, "$pkgname-$pkgver", "japan-razer");
printf("|%d|%s\n", strlen(a), a);
return 0;
}
