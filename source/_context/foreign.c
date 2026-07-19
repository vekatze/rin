#include <curl/curl.h>

__attribute__((always_inline))
int neut_rin_v0_2_CURL_GLOBAL_DEFAULT() {
  return CURL_GLOBAL_DEFAULT;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLH_HEADER() {
  return CURLH_HEADER;
}

__attribute__((always_inline))
char *neut_rin_v0_2_get_header_name(struct curl_header *h) {
  return h->name;
}

__attribute__((always_inline))
char *neut_rin_v0_2_get_header_value(struct curl_header *h) {
  return h->value;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLINFO_RESPONSE_CODE() {
  return CURLINFO_RESPONSE_CODE;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_CUSTOMREQUEST() {
  return CURLOPT_CUSTOMREQUEST;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_FOLLOWLOCATION() {
  return CURLOPT_FOLLOWLOCATION;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_HTTPHEADER() {
  return CURLOPT_HTTPHEADER;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_POSTFIELDS() {
  return CURLOPT_POSTFIELDS;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_POSTFIELDSIZE() {
  return CURLOPT_POSTFIELDSIZE;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_TIMEOUT() {
  return CURLOPT_TIMEOUT;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_URL() {
  return CURLOPT_URL;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_WRITEFUNCTION() {
  return CURLOPT_WRITEFUNCTION;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_WRITEDATA() {
  return CURLOPT_WRITEDATA;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_HEADERFUNCTION() {
  return CURLOPT_HEADERFUNCTION;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLOPT_HEADERDATA() {
  return CURLOPT_HEADERDATA;
}

__attribute__((always_inline))
int neut_rin_v0_2_CURLE_OK() {
  return CURLE_OK;
}
