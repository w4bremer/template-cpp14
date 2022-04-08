# Change Log

All notable changes to this project will be documented in this file.
See [Conventional Commits](https://conventionalcommits.org) for commit guidelines.

# [2.0.0](https://github.com/apigear-io/objectapi-generator/compare/@apigear-io-templates/cpp14-blueprint@1.14.0...@apigear-io-templates/cpp14-blueprint@2.0.0) (2022-03-30)


### Bug Fixes

* **cpp14:** Add missing library link for test ([bf1b82c](https://github.com/apigear-io/objectapi-generator/commit/bf1b82c0d8c2add17b76dd39990561af4cb3ce8d))
* **cpp14:** Add missing lohmann dep to core ([71c49d5](https://github.com/apigear-io/objectapi-generator/commit/71c49d59949c9f2c0c8018c86fea1d8d1e93696e))
* **cpp14:** Add static libs to conan distributed packages ([1c5d2f3](https://github.com/apigear-io/objectapi-generator/commit/1c5d2f3fdeb37161caf1c1cba59b07fbedfb82c8))
* **cpp14:** Add threads lib to link dependencies ([312065d](https://github.com/apigear-io/objectapi-generator/commit/312065dafcd44f09464d512eb7afe73f83554cbf))
* **cpp14:** Check for correct olinkserver path ([5721363](https://github.com/apigear-io/objectapi-generator/commit/57213630bf5b3b5e403ffec6eefeaec090262551))
* **cpp14:** Clean up tracer and decorator publisher impl ([4fe9bae](https://github.com/apigear-io/objectapi-generator/commit/4fe9bae9d8f055e0382cd470706be5a32866cb2b))
* **cpp14:** Convert async promise to future ([b7475ca](https://github.com/apigear-io/objectapi-generator/commit/b7475cacab5848efcdbc89569d5e136339df2d5f))
* **cpp14:** Corrected linking of api to core lib ([01818e2](https://github.com/apigear-io/objectapi-generator/commit/01818e2698f02d8477fe82511d83276e69f9164f))
* **cpp14:** Deactivate conan env after test ([26fdef4](https://github.com/apigear-io/objectapi-generator/commit/26fdef45ae811739d999f7f9a5c75bbce46d6f13))
* **cpp14:** Directly init return value ([6891087](https://github.com/apigear-io/objectapi-generator/commit/6891087e95cfac7dab7b456a71abaacfb834a23e))
* **cpp14:** Disable C4251 warning for now ([7586c91](https://github.com/apigear-io/objectapi-generator/commit/7586c91054af441cccd2ebee2453975f9ba6acbc))
* **cpp14:** Disable useless warning C4250 ([c089263](https://github.com/apigear-io/objectapi-generator/commit/c089263ddf9d1165c86677a0e583a9dc0565c4b9))
* **cpp14:** Do not overwrite impl files unless enforced ([5c11d71](https://github.com/apigear-io/objectapi-generator/commit/5c11d716d52773bef5388321c7f1f66c043a2e97))
* **cpp14:** Do not use dllexport on enums ([7275af3](https://github.com/apigear-io/objectapi-generator/commit/7275af3febdfdcd2a7701fe9f6ba21d95a970c53))
* **cpp14:** Enable fpic for module api part ([041470c](https://github.com/apigear-io/objectapi-generator/commit/041470c64c761aa4607058ff17f374b79523cffb))
* **cpp14:** Export symbols for windows build ([418efd3](https://github.com/apigear-io/objectapi-generator/commit/418efd3045a1891c92b77541ec54bf7a2f8d3886))
* **cpp14:** Fix conan include paths ([bc81ca7](https://github.com/apigear-io/objectapi-generator/commit/bc81ca7d37cfe8ffd31dcba06c31d8c4a91aa7ac))
* **cpp14:** Fix conan linux build ([0aff702](https://github.com/apigear-io/objectapi-generator/commit/0aff70216707783f2c9a5fecf5367d2de22a0400))
* **cpp14:** Fix conan test_package ([ddc1458](https://github.com/apigear-io/objectapi-generator/commit/ddc1458205599c4fd5d41d09edf91a4bae9f12dc))
* **cpp14:** Fix conan test_package ([7b4ffd7](https://github.com/apigear-io/objectapi-generator/commit/7b4ffd722a857316da6665a19caccf1fb44cc467))
* **cpp14:** Fix conan test_package ([97e8c12](https://github.com/apigear-io/objectapi-generator/commit/97e8c1240371311eb2bb1b4ac20eee8d97694edb))
* **cpp14:** Fix extra qualification of data struct ([0177f2a](https://github.com/apigear-io/objectapi-generator/commit/0177f2ae4ae589a44cfee0d81a94b2d80b8b2b46))
* **cpp14:** Fix header includes for consumers ([2da3ef1](https://github.com/apigear-io/objectapi-generator/commit/2da3ef107122705058e3d1491afdd009d6a2c3f0))
* **cpp14:** Fix olink client conneciton loss handling ([8c2b1d1](https://github.com/apigear-io/objectapi-generator/commit/8c2b1d151459383f958f1e571b843cb7a4a2e5f1))
* **cpp14:** Fix several olink connection issues ([e8fecfa](https://github.com/apigear-io/objectapi-generator/commit/e8fecfa9fedd95b1024ba60eaf7bae2701ffee84))
* **cpp14:** Fix tracer connection handling ([eee470b](https://github.com/apigear-io/objectapi-generator/commit/eee470b7675bd1b34b1d9ca521002a063c46e94e))
* **cpp14:** Fix unused param in olink async call ([6971004](https://github.com/apigear-io/objectapi-generator/commit/6971004765a16c3a77e8ec567f92b7f4a2ffa6fe))
* **cpp14:** Fixe olink host connection handling ([6cacc8c](https://github.com/apigear-io/objectapi-generator/commit/6cacc8c1e83ef0222b7ff8826ae6baed152a4020))
* **cpp14:** Fixed d_ptr implementation of service class ([21302dd](https://github.com/apigear-io/objectapi-generator/commit/21302ddacbba6f46ac7ef9caa14f44f276db073e))
* **cpp14:** Ignore unused olink signal paramter ([e6b9c35](https://github.com/apigear-io/objectapi-generator/commit/e6b9c350e4cf22ff68341d0ac50524344f8a05fc))
* **cpp14:** Make PCRE lib fix globally available ([24c8319](https://github.com/apigear-io/objectapi-generator/commit/24c83195ea96aeb8bb8335e9ea035da62df225b0))
* **cpp14:** Make sure json conversion is declared only once ([a578c89](https://github.com/apigear-io/objectapi-generator/commit/a578c898874060ebad5123b7d2ab3ee9e12bc216))
* **cpp14:** Mark publish functions as const ([a9350ae](https://github.com/apigear-io/objectapi-generator/commit/a9350aeeaae7439eec9f44f960f6d6d030be3798))
* **cpp14:** More 20.04 ubuntu pendantic fixes ([16eaca5](https://github.com/apigear-io/objectapi-generator/commit/16eaca58fe052dedbe831f08354f9fcb1182d0a8))
* **cpp14:** Name callback functions typedefs uniquely ([79622d6](https://github.com/apigear-io/objectapi-generator/commit/79622d6739c7c91cbf413f39c10e342f1759000d))
* **cpp14:** Only generate support files with scaffold ([4bf0865](https://github.com/apigear-io/objectapi-generator/commit/4bf0865c1e6ce1b9be3c4c8fce89bb56e4fe35eb))
* **cpp14:** Prevent duplicate websocket connections ([494ee99](https://github.com/apigear-io/objectapi-generator/commit/494ee99a317fc6580f21cab3c19e72add6e926a7))
* **cpp14:** Properly unsubscribe from olink property changes ([f621004](https://github.com/apigear-io/objectapi-generator/commit/f6210042457c7b579e97dc07fb02a13de2adaaa9))
* **cpp14:** Remove ; from pedantic errors ([a6b81be](https://github.com/apigear-io/objectapi-generator/commit/a6b81be94b4b5b399c33c4e61746e485fe4c2d7c))
* **cpp14:** Remove d_ptr leftover ([d8dc9e0](https://github.com/apigear-io/objectapi-generator/commit/d8dc9e059921034e691e408ae21280c50ddbd0fd))
* **cpp14:** Remove enum forward declaration ([76673d8](https://github.com/apigear-io/objectapi-generator/commit/76673d88a445456253961017040c09c5b33c72f9))
* **cpp14:** Remove superfluous virtual in olinkinterface ([c2920e7](https://github.com/apigear-io/objectapi-generator/commit/c2920e7fdd251ddb58e2b7dd833110abfbd44a27))
* **cpp14:** Remove tracer leftovers from service implementation ([45748b2](https://github.com/apigear-io/objectapi-generator/commit/45748b2ca4846bd41c755824d5866c88f2e74cc5))
* **cpp14:** Remove virtual function decl from decorator class ([05750b0](https://github.com/apigear-io/objectapi-generator/commit/05750b0acb4e5b89f680f55f8a6361bed7bd09e0))
* **cpp14:** Rename fcn parameters to avoid accidential shadowing ([912572a](https://github.com/apigear-io/objectapi-generator/commit/912572a5b2b8cc058adbb788dad409f5094077cf))
* **cpp14:** Return const ref declaration ([3744d43](https://github.com/apigear-io/objectapi-generator/commit/3744d43ab15700794570b2cd9a195636f7a8fe84))
* **cpp14:** Set correct include path in conan package test ([2952861](https://github.com/apigear-io/objectapi-generator/commit/29528611f2d88c2ec3f9a2b168b1fc9c579d845c))
* **cpp14:** Set correct symbol export on windows ([2d19563](https://github.com/apigear-io/objectapi-generator/commit/2d1956391d2c14dd4fc38972aebe171d2053398e))
* **cpp14:** Switch poco targets depending on OS ([71dde71](https://github.com/apigear-io/objectapi-generator/commit/71dde716b62b7ec7d3770caf3cb7e6a38b9e6108))
* **cpp14:** Update tracer to current protocol ([a9a3272](https://github.com/apigear-io/objectapi-generator/commit/a9a327252375c28edf44595191a8090f2ab8f2fe))
* **cpp14:** Use constant for systemname in export macro ([32dc2db](https://github.com/apigear-io/objectapi-generator/commit/32dc2db1fea2172fb60ba7e944d9759382974c99))
* **cpp14:** Use default initialization for datastruct members ([e8945b8](https://github.com/apigear-io/objectapi-generator/commit/e8945b89dcecd88d829b37f8b361bbf07b10abbe))
* **cpp14:** Use escaped name in testpackage ([8ddec37](https://github.com/apigear-io/objectapi-generator/commit/8ddec378edd94de2039f3bf062c7691fc438a1ce))
* **cpp14:** Use unique module_interface names for files ([a176224](https://github.com/apigear-io/objectapi-generator/commit/a17622427186d23afe0819fe48bf30b0cf2e19a5))
* **cpp14:** Wrap pimpl declaration in namespace ([a25fd0a](https://github.com/apigear-io/objectapi-generator/commit/a25fd0a0e75364b455f9d03213b583706466144e))


### Features

* **cpp14:** Add async functions to interface ([ce2b2fc](https://github.com/apigear-io/objectapi-generator/commit/ce2b2fc46fe5a5120be47e52c78059971659b414))
* **cpp14:** Add basic olink implementation to apigear lib ([3c6cc45](https://github.com/apigear-io/objectapi-generator/commit/3c6cc457dc0298ec9ba3e89d093d5193669bc18e))
* **cpp14:** Add examples app ([826c9c2](https://github.com/apigear-io/objectapi-generator/commit/826c9c278e99382b91831a27f505b2fb9edfc972))
* **cpp14:** Add simple olinkserver example ([c82bb8e](https://github.com/apigear-io/objectapi-generator/commit/c82bb8ed833b7dda13baa58055bdf1f4916e8ad3))
* **cpp14:** Add test_conan.bat for conan on Windows ([942e038](https://github.com/apigear-io/objectapi-generator/commit/942e0382bee9691b5c5a23a0be885ccec5728d2e))
* **cpp14:** Added client proxy with tracing ([6cf02d6](https://github.com/apigear-io/objectapi-generator/commit/6cf02d6acf0fff8fae87254233d5beb93014fb6f))
* **cpp14:** Declare conan as separate feature ([3dbf9e3](https://github.com/apigear-io/objectapi-generator/commit/3dbf9e35d1e0abf2ac2bb15590d824b31731c8be))
* **cpp14:** Enable passthrough for publisher and proxy ([2580b8e](https://github.com/apigear-io/objectapi-generator/commit/2580b8e4335e57b0a7a509dc6ad4352332c48cf1))
* **cpp14:** First version olink adapters ([dcf501f](https://github.com/apigear-io/objectapi-generator/commit/dcf501fbcd8b74fc77335e3843e623701a6c099c))
* **cpp14:** First version olink client interface ([c7bad6e](https://github.com/apigear-io/objectapi-generator/commit/c7bad6efbbd0804785db39985b56272660d13d52))
* **cpp14:** Implement flexible func callbacks ([21e47a2](https://github.com/apigear-io/objectapi-generator/commit/21e47a2dc9863267f9f81e304a1d54e87fe8b9a8))
* **cpp14:** Improve olink connection handling ([6ee5fd6](https://github.com/apigear-io/objectapi-generator/commit/6ee5fd606d23b30d2d9fd46fa31711eb4f01f194))
* **cpp14:** Introduce module namespace ([87bbe65](https://github.com/apigear-io/objectapi-generator/commit/87bbe65a256f49dcda1d3d567b1b42377e178615))


### Reverts

* Revert "refactor(cpp14): Explicitly forward fnc calls" ([bc18b76](https://github.com/apigear-io/objectapi-generator/commit/bc18b76b2dd235c5989a3262f263558dcfcd3ad8))





# [1.14.0](https://github.com/apigear-io/objectapi-generator/compare/@apigear-io-templates/cpp14-blueprint@1.12.0...@apigear-io-templates/cpp14-blueprint@1.14.0) (2021-04-22)

**Note:** Version bump only for package @apigear-io-templates/cpp14-blueprint





# 1.12.0 (2021-04-22)

**Note:** Version bump only for package @apigear-io-templates/cpp14-blueprint






# [1.11.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.11.0) (2021-03-04)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint






# [1.8.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.8.0) (2021-02-16)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





# [1.7.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.7.0) (2021-02-15)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





# [1.6.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.6.0) (2021-02-15)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





## [1.4.3](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.4.3) (2021-01-31)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





# [1.4.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.4.0) (2021-01-28)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





# [1.2.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.2.0) (2021-01-28)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





# [1.1.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.1.0) (2021-01-10)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint





# [1.0.0](https://github.com/apigear-io/objectapi-generator/compare/v0.6.1...v1.0.0) (2021-01-09)

**Note:** Version bump only for package @apigear-io/cpp14-blueprint
