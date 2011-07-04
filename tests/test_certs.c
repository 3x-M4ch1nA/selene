/*
 * Licensed to Selene developers ('Selene') under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * Selene licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "selene.h"
#include "sln_tests.h"
#include "sln_certs.h"
#include <string.h>

unsigned char public_cert_apache_org[] = {
0x30, 0x82, 0x05, 
0x0b, 0x30, 0x82, 0x04, 0x74, 0xa0, 0x03, 0x02, 
0x01, 0x02, 0x02, 0x10, 0x05, 0x56, 0x06, 0xdf, 
0x28, 0x00, 0xce, 0x45, 0x2d, 0xf2, 0x5d, 0x40, 
0xa2, 0x4c, 0xe9, 0xb0, 0x30, 0x0d, 0x06, 0x09, 
0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 
0x05, 0x05, 0x00, 0x30, 0x81, 0xce, 0x31, 0x0b, 
0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 
0x02, 0x5a, 0x41, 0x31, 0x15, 0x30, 0x13, 0x06, 
0x03, 0x55, 0x04, 0x08, 0x13, 0x0c, 0x57, 0x65, 
0x73, 0x74, 0x65, 0x72, 0x6e, 0x20, 0x43, 0x61, 
0x70, 0x65, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 
0x55, 0x04, 0x07, 0x13, 0x09, 0x43, 0x61, 0x70, 
0x65, 0x20, 0x54, 0x6f, 0x77, 0x6e, 0x31, 0x1d, 
0x30, 0x1b, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13, 
0x14, 0x54, 0x68, 0x61, 0x77, 0x74, 0x65, 0x20, 
0x43, 0x6f, 0x6e, 0x73, 0x75, 0x6c, 0x74, 0x69, 
0x6e, 0x67, 0x20, 0x63, 0x63, 0x31, 0x28, 0x30, 
0x26, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x13, 0x1f, 
0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 
0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x53, 0x65, 
0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x20, 0x44, 
0x69, 0x76, 0x69, 0x73, 0x69, 0x6f, 0x6e, 0x31, 
0x21, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x04, 0x03, 
0x13, 0x18, 0x54, 0x68, 0x61, 0x77, 0x74, 0x65, 
0x20, 0x50, 0x72, 0x65, 0x6d, 0x69, 0x75, 0x6d, 
0x20, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x20, 
0x43, 0x41, 0x31, 0x28, 0x30, 0x26, 0x06, 0x09, 
0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 
0x01, 0x16, 0x19, 0x70, 0x72, 0x65, 0x6d, 0x69, 
0x75, 0x6d, 0x2d, 0x73, 0x65, 0x72, 0x76, 0x65, 
0x72, 0x40, 0x74, 0x68, 0x61, 0x77, 0x74, 0x65, 
0x2e, 0x63, 0x6f, 0x6d, 0x30, 0x1e, 0x17, 0x0d, 
0x30, 0x39, 0x31, 0x32, 0x33, 0x30, 0x30, 0x30, 
0x30, 0x30, 0x30, 0x30, 0x5a, 0x17, 0x0d, 0x31, 
0x31, 0x31, 0x32, 0x33, 0x30, 0x32, 0x33, 0x35, 
0x39, 0x35, 0x39, 0x5a, 0x30, 0x81, 0x8b, 0x31, 
0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 
0x13, 0x02, 0x55, 0x53, 0x31, 0x11, 0x30, 0x0f, 
0x06, 0x03, 0x55, 0x04, 0x08, 0x13, 0x08, 0x4d, 
0x61, 0x72, 0x79, 0x6c, 0x61, 0x6e, 0x64, 0x31, 
0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x07, 
0x14, 0x0b, 0x46, 0x6f, 0x72, 0x65, 0x73, 0x74, 
0x20, 0x48, 0x69, 0x6c, 0x6c, 0x31, 0x23, 0x30, 
0x21, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x14, 0x1a, 
0x41, 0x70, 0x61, 0x63, 0x68, 0x65, 0x20, 0x53, 
0x6f, 0x66, 0x74, 0x77, 0x61, 0x72, 0x65, 0x20, 
0x46, 0x6f, 0x75, 0x6e, 0x64, 0x61, 0x74, 0x69, 
0x6f, 0x6e, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 
0x55, 0x04, 0x0b, 0x14, 0x0e, 0x49, 0x6e, 0x66, 
0x72, 0x61, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 
0x75, 0x72, 0x65, 0x31, 0x15, 0x30, 0x13, 0x06, 
0x03, 0x55, 0x04, 0x03, 0x14, 0x0c, 0x2a, 0x2e, 
0x61, 0x70, 0x61, 0x63, 0x68, 0x65, 0x2e, 0x6f, 
0x72, 0x67, 0x30, 0x82, 0x02, 0x22, 0x30, 0x0d, 
0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 
0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x02, 
0x0f, 0x00, 0x30, 0x82, 0x02, 0x0a, 0x02, 0x82, 
0x02, 0x01, 0x00, 0xea, 0x8d, 0x70, 0x7d, 0xaa, 
0x65, 0x56, 0xc8, 0x1a, 0xa9, 0xfb, 0x8d, 0xd8, 
0xbc, 0xf2, 0x37, 0xba, 0xc4, 0xfd, 0x6f, 0xa8, 
0x60, 0x1f, 0x42, 0xd1, 0xa9, 0x27, 0x2a, 0x7b, 
0x55, 0x27, 0x3d, 0xfb, 0x7d, 0x52, 0x2c, 0x7f, 
0x48, 0xbb, 0x7a, 0x06, 0x7c, 0x54, 0xee, 0xdb, 
0xed, 0x02, 0x87, 0x5b, 0xca, 0x7d, 0xfe, 0x76, 
0x5b, 0x79, 0x08, 0xee, 0x04, 0xe5, 0x07, 0xba, 
0xd8, 0xf4, 0x02, 0xff, 0xa0, 0xc9, 0x61, 0x84, 
0x45, 0x40, 0x74, 0x7f, 0x0f, 0xcc, 0xc6, 0xfe, 
0x0c, 0xdb, 0xcb, 0x5d, 0x32, 0x3a, 0x4e, 0x0b, 
0xab, 0xbc, 0x4e, 0x1a, 0xb9, 0xa2, 0x6d, 0x8d, 
0xf2, 0xf5, 0x48, 0x1c, 0xf9, 0x84, 0xe9, 0x26, 
0x84, 0xae, 0x69, 0x04, 0xdb, 0x34, 0x7e, 0x70, 
0x60, 0x74, 0x0e, 0x5b, 0x3e, 0xf6, 0xa7, 0x69, 
0x54, 0x9c, 0x0f, 0xe3, 0x38, 0x5c, 0x47, 0x7d, 
0xb2, 0x60, 0xa8, 0x0c, 0x07, 0x2d, 0x28, 0x64, 
0xe3, 0x01, 0x20, 0xbb, 0x20, 0x43, 0x3a, 0x5f, 
0x4d, 0x8d, 0xd0, 0x73, 0x83, 0xbe, 0x86, 0x2e, 
0x37, 0xe1, 0xe6, 0xf7, 0x71, 0xf6, 0x47, 0x4f, 
0x55, 0xe6, 0xf3, 0x4f, 0xd2, 0x28, 0x5e, 0x70, 
0x18, 0xd8, 0x61, 0x2e, 0xfa, 0x83, 0xf7, 0xf8, 
0xe2, 0x2e, 0xaa, 0x72, 0xb7, 0x5f, 0x91, 0x73, 
0x24, 0x5c, 0xa9, 0x07, 0xae, 0x0c, 0xbe, 0x9c, 
0x55, 0xd0, 0xdb, 0x8d, 0xad, 0xc1, 0x0a, 0x78, 
0xc7, 0x9a, 0x53, 0x49, 0x26, 0xe4, 0xfe, 0xa6, 
0x75, 0xb3, 0x92, 0xf0, 0x6e, 0x18, 0x41, 0xa6, 
0xb8, 0xaf, 0x3c, 0x73, 0xc0, 0x7f, 0xca, 0x11, 
0x5b, 0xf0, 0xfb, 0x68, 0x7d, 0xa1, 0x78, 0x07, 
0x84, 0xe5, 0x5d, 0x43, 0x12, 0x66, 0x6d, 0x7e, 
0x60, 0x23, 0x35, 0xc1, 0x3a, 0x69, 0x2f, 0x35, 
0x9b, 0x79, 0x7a, 0x6c, 0xfd, 0x5a, 0x35, 0x83, 
0x07, 0xfb, 0x2f, 0x4b, 0x40, 0xc0, 0xc5, 0x6e, 
0xeb, 0x6f, 0x9d, 0xbc, 0xb9, 0x73, 0xe0, 0x7a, 
0x4b, 0x50, 0x39, 0x3f, 0xa4, 0x6f, 0x7e, 0x0c, 
0x06, 0x34, 0xd6, 0xb3, 0x25, 0xd4, 0x18, 0x57, 
0x2a, 0x15, 0xf4, 0x66, 0x99, 0xc7, 0x17, 0x5c, 
0xbf, 0xf3, 0x5a, 0x72, 0x80, 0x29, 0xfa, 0x23, 
0xf0, 0x1d, 0x9d, 0x44, 0x52, 0x15, 0x89, 0x99, 
0x04, 0xc1, 0x1e, 0x31, 0x37, 0xac, 0x3d, 0x90, 
0x7d, 0xc7, 0x50, 0x1a, 0xd5, 0x76, 0xca, 0xfc, 
0xbd, 0x53, 0x19, 0x1e, 0xa2, 0xbc, 0xd7, 0x96, 
0x35, 0x35, 0xb5, 0x11, 0x32, 0x41, 0x25, 0x38, 
0x57, 0x6b, 0xa6, 0x81, 0x15, 0x46, 0x08, 0xa9, 
0x66, 0xdc, 0xd0, 0x35, 0xd2, 0x13, 0x9d, 0x23, 
0xe4, 0x20, 0xec, 0xf4, 0x23, 0x81, 0xa7, 0xa1, 
0x4d, 0x4a, 0x1f, 0x44, 0x97, 0x82, 0x3b, 0x82, 
0x6e, 0xb8, 0x96, 0x84, 0x31, 0xf9, 0xeb, 0x98, 
0x30, 0xd7, 0x39, 0xca, 0xcc, 0x67, 0xe8, 0x0b, 
0xfb, 0xda, 0xef, 0x2b, 0x08, 0xd5, 0x2b, 0xf4, 
0xf3, 0x15, 0xcf, 0x6c, 0xd2, 0xc3, 0x94, 0x2d, 
0xb1, 0x3b, 0xee, 0xde, 0x0c, 0xd7, 0x91, 0xfc, 
0xa0, 0x68, 0x20, 0x17, 0x66, 0x70, 0xf4, 0xa3, 
0x05, 0xb6, 0xf5, 0x34, 0x04, 0x61, 0x94, 0xc1, 
0x97, 0xaf, 0x91, 0xdb, 0xdc, 0x21, 0xd5, 0xdb, 
0x70, 0xeb, 0xf7, 0xe2, 0x26, 0xba, 0xb2, 0x7f, 
0x00, 0xb7, 0x08, 0x21, 0xd0, 0xed, 0x54, 0x09, 
0x63, 0x97, 0xa0, 0xd5, 0xa7, 0xcd, 0x3e, 0x27,
0xa4, 0x71, 0xeb, 0x67, 0x67, 0x67, 0xb0, 0xe0, 
0x68, 0x09, 0x66, 0x7c, 0x44, 0x64, 0x5c, 0x8f, 
0x33, 0xff, 0xfe, 0xb7, 0xfc, 0x11, 0xe9, 0xf7, 
0x58, 0x95, 0x73, 0xc8, 0x11, 0xcb, 0x1f, 0x8b, 
0x83, 0xf8, 0x4e, 0xb7, 0x14, 0xb1, 0xa5, 0x53, 
0x26, 0x62, 0x79, 0xfa, 0x30, 0x7b, 0x0c, 0x8a, 
0xec, 0x2a, 0xe5, 0x02, 0x03, 0x01, 0x00, 0x01, 
0xa3, 0x81, 0xa6, 0x30, 0x81, 0xa3, 0x30, 0x0c, 
0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 
0x04, 0x02, 0x30, 0x00, 0x30, 0x40, 0x06, 0x03, 
0x55, 0x1d, 0x1f, 0x04, 0x39, 0x30, 0x37, 0x30, 
0x35, 0xa0, 0x33, 0xa0, 0x31, 0x86, 0x2f, 0x68, 
0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x63, 0x72, 
0x6c, 0x2e, 0x74, 0x68, 0x61, 0x77, 0x74, 0x65, 
0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x54, 0x68, 0x61, 
0x77, 0x74, 0x65, 0x53, 0x65, 0x72, 0x76, 0x65, 
0x72, 0x50, 0x72, 0x65, 0x6d, 0x69, 0x75, 0x6d, 
0x43, 0x41, 0x2e, 0x63, 0x72, 0x6c, 0x30, 0x1d, 
0x06, 0x03, 0x55, 0x1d, 0x25, 0x04, 0x16, 0x30, 
0x14, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 
0x07, 0x03, 0x01, 0x06, 0x08, 0x2b, 0x06, 0x01, 
0x05, 0x05, 0x07, 0x03, 0x02, 0x30, 0x32, 0x06, 
0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x01, 
0x01, 0x04, 0x26, 0x30, 0x24, 0x30, 0x22, 0x06, 
0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x30, 
0x01, 0x86, 0x16, 0x68, 0x74, 0x74, 0x70, 0x3a, 
0x2f, 0x2f, 0x6f, 0x63, 0x73, 0x70, 0x2e, 0x74, 
0x68, 0x61, 0x77, 0x74, 0x65, 0x2e, 0x63, 0x6f, 
0x6d, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 
0x86, 0xf7, 0x0d, 0x01, 0x01, 0x05, 0x05, 0x00, 
0x03, 0x81, 0x81, 0x00, 0x8d, 0xec, 0x36, 0xee, 
0x5f, 0xc0, 0xda, 0x3b, 0x15, 0x1e, 0x0b, 0x02, 
0x8c, 0x94, 0x67, 0xd2, 0x9f, 0x9e, 0x0b, 0xdb, 
0x34, 0x8a, 0x1e, 0x9d, 0x45, 0xf1, 0x68, 0xd8, 
0xdf, 0x4b, 0x16, 0x43, 0xdc, 0x0e, 0x47, 0x95, 
0x94, 0x36, 0xe8, 0x06, 0xf8, 0xb1, 0x18, 0xc9, 
0x8d, 0x60, 0xc2, 0x26, 0xa4, 0xdc, 0xe4, 0x01, 
0xce, 0xe0, 0x90, 0x19, 0xe8, 0x84, 0x2f, 0x4b, 
0x4e, 0xba, 0x9f, 0x86, 0x0a, 0x51, 0xdc, 0xb8, 
0xc1, 0x70, 0xdb, 0xb6, 0x47, 0xb6, 0x98, 0xd6, 
0x30, 0x9f, 0xb7, 0x6c, 0xa4, 0xb6, 0xdf, 0x9f, 
0xd6, 0x57, 0x69, 0xd4, 0x9f, 0x28, 0x97, 0xd8, 
0xb2, 0x55, 0xf2, 0xb6, 0x35, 0xa0, 0xf9, 0x7d, 
0xa5, 0x69, 0x30, 0xf9, 0x83, 0x77, 0x9b, 0x4b, 
0x1e, 0x39, 0x84, 0x55, 0xba, 0x4c, 0xa0, 0x64, 
0xd4, 0x14, 0x00, 0x62, 0xa0, 0xaf, 0x30, 0x12, 
0x50, 0x05, 0x64, 0x1d };

static void
init_cert(void **state, selene_t **s_, selene_conf_t **conf_, selene_cert_t **cert_)
{
  selene_t *s = NULL;
  selene_conf_t *conf = NULL;
  selene_cert_t *cert = NULL;
  X509 *x509;

  selene_conf_create(&conf);
  SLN_ERR(selene_conf_use_reasonable_defaults(conf));
  SLN_ERR(selene_server_create(conf, &s));
  SLN_ASSERT_CONTEXT(s);

  unsigned char *p = &public_cert_apache_org[0];

  x509 = d2i_X509(NULL, (const unsigned char **)&p, sizeof(public_cert_apache_org));

  SLN_ERR(sln_cert_create(s, x509, 0, &cert));

  *s_ = s;
  *conf_ = conf;
  *cert_ = cert;
}


static void
destroy_cert(void **state, selene_t *s, selene_conf_t *conf, selene_cert_t *cert)
{
  sln_cert_destroy(cert);
  selene_destroy(s);
  selene_conf_destroy(conf);
}

static void
cert_depth(void **state)
{
  selene_t *s;
  selene_conf_t *conf;
  selene_cert_t *cert;

  init_cert(state, &s, &conf, &cert);

  assert_int_equal(0, selene_cert_depth(cert));

  destroy_cert(state, s, conf, cert);
}

static void
cert_fingerprints(void **state)
{
  selene_t *s;
  selene_conf_t *conf;
  selene_cert_t *cert;

  init_cert(state, &s, &conf, &cert);

  assert_string_equal("9A:A9:71:5B:98:3E:50:D7:B5:90:85:26:AB:34:27:33",
                      selene_cert_fingerprint_md5(cert));

  assert_string_equal("19:C3:BA:6B:1F:82:42:2A:CE:46:E0:B7:E3:0D:33:CD:53:B4:6E:52",
                      selene_cert_fingerprint_sha1(cert));

  destroy_cert(state, s, conf, cert);
}

static void
cert_subject(void **state)
{
  selene_t *s;
  selene_conf_t *conf;
  selene_cert_t *cert;
  selene_cert_name_t *name;

  init_cert(state, &s, &conf, &cert);

  name = selene_cert_subject(cert);

  assert_int_not_equal(0, name);

  assert_string_equal("*.apache.org", name->commonName);
  assert_int_equal(0, name->emailAddress);
  assert_string_equal("Infrastructure", name->organizationalUnitName);
  assert_string_equal("Apache Software Foundation", name->organizationName);
  assert_string_equal("Forest Hill", name->localityName);
  assert_string_equal("Maryland", name->stateOrProvinceName);
  assert_string_equal("US", name->countryName);

  destroy_cert(state, s, conf, cert);
}


static void
cert_issuer(void **state)
{
  selene_t *s;
  selene_conf_t *conf;
  selene_cert_t *cert;
  selene_cert_name_t *name;

  init_cert(state, &s, &conf, &cert);

  name = selene_cert_issuer(cert);

  assert_int_not_equal(0, name);

  assert_string_equal("Thawte Premium Server CA", name->commonName);
  assert_string_equal("premium-server@thawte.com", name->emailAddress);
  assert_string_equal("Certification Services Division", name->organizationalUnitName);
  assert_string_equal("Thawte Consulting cc", name->organizationName);
  assert_string_equal("Cape Town", name->localityName);
  assert_string_equal("Western Cape", name->stateOrProvinceName);
  assert_string_equal("ZA", name->countryName);

  destroy_cert(state, s, conf, cert);
}

static void
cert_validtime(void **state)
{
  selene_t *s;
  selene_conf_t *conf;
  selene_cert_t *cert;

  init_cert(state, &s, &conf, &cert);

  assert_string_equal("Dec 30 00:00:00 2009 GMT", selene_cert_not_before_str(cert));
  assert_string_equal("Dec 30 23:59:59 2011 GMT", selene_cert_not_after_str(cert));
  assert_int_equal(1262217600, selene_cert_not_before(cert));
  assert_int_equal(1325375999, selene_cert_not_after(cert));

  destroy_cert(state, s, conf, cert);
}

SLN_TESTS_START(certs)
  SLN_TESTS_ENTRY(cert_depth)
  SLN_TESTS_ENTRY(cert_fingerprints)
  SLN_TESTS_ENTRY(cert_subject)
  SLN_TESTS_ENTRY(cert_issuer)
  SLN_TESTS_ENTRY(cert_validtime)
SLN_TESTS_END()
