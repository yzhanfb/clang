/*===--- __clang_cuda_intrinsics.h - Device-side CUDA intrinsic wrappers ---===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */
#ifndef __CLANG_CUDA_INTRINSICS_H__
#define __CLANG_CUDA_INTRINSICS_H__
#ifndef __CUDA__
#error "This file is for CUDA compilation only."
#endif

// sm_32 intrinsics: __ldg and __funnelshift_{l,lc,r,rc}.

// Prevent the vanilla sm_32 intrinsics header from being included.
#define __SM_32_INTRINSICS_H__
#define __SM_32_INTRINSICS_HPP__

#if !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 320

inline __device__ char __ldg(const char *ptr) { return __nvvm_ldg_c(ptr); }
inline __device__ short __ldg(const short *ptr) { return __nvvm_ldg_s(ptr); }
inline __device__ int __ldg(const int *ptr) { return __nvvm_ldg_i(ptr); }
inline __device__ long __ldg(const long *ptr) { return __nvvm_ldg_l(ptr); }
inline __device__ long long __ldg(const long long *ptr) {
  return __nvvm_ldg_ll(ptr);
}
inline __device__ unsigned char __ldg(const unsigned char *ptr) {
  return __nvvm_ldg_uc(ptr);
}
inline __device__ unsigned short __ldg(const unsigned short *ptr) {
  return __nvvm_ldg_us(ptr);
}
inline __device__ unsigned int __ldg(const unsigned int *ptr) {
  return __nvvm_ldg_ui(ptr);
}
inline __device__ unsigned long __ldg(const unsigned long *ptr) {
  return __nvvm_ldg_ul(ptr);
}
inline __device__ unsigned long long __ldg(const unsigned long long *ptr) {
  return __nvvm_ldg_ull(ptr);
}
inline __device__ float __ldg(const float *ptr) { return __nvvm_ldg_f(ptr); }
inline __device__ double __ldg(const double *ptr) { return __nvvm_ldg_d(ptr); }

inline __device__ char2 __ldg(const char2 *ptr) {
  typedef char c2 __attribute__((ext_vector_type(2)));
  // We can assume that ptr is aligned at least to char2's alignment, but the
  // load will assume that ptr is aligned to char2's alignment.  This is only
  // safe if alignof(c2) <= alignof(char2).
  c2 rv = __nvvm_ldg_c2(reinterpret_cast<const c2 *>(ptr));
  char2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ char4 __ldg(const char4 *ptr) {
  typedef char c4 __attribute__((ext_vector_type(4)));
  c4 rv = __nvvm_ldg_c4(reinterpret_cast<const c4 *>(ptr));
  char4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ short2 __ldg(const short2 *ptr) {
  typedef short s2 __attribute__((ext_vector_type(2)));
  s2 rv = __nvvm_ldg_s2(reinterpret_cast<const s2 *>(ptr));
  short2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ short4 __ldg(const short4 *ptr) {
  typedef short s4 __attribute__((ext_vector_type(4)));
  s4 rv = __nvvm_ldg_s4(reinterpret_cast<const s4 *>(ptr));
  short4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ int2 __ldg(const int2 *ptr) {
  typedef int i2 __attribute__((ext_vector_type(2)));
  i2 rv = __nvvm_ldg_i2(reinterpret_cast<const i2 *>(ptr));
  int2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ int4 __ldg(const int4 *ptr) {
  typedef int i4 __attribute__((ext_vector_type(4)));
  i4 rv = __nvvm_ldg_i4(reinterpret_cast<const i4 *>(ptr));
  int4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ longlong2 __ldg(const longlong2 *ptr) {
  typedef long long ll2 __attribute__((ext_vector_type(2)));
  ll2 rv = __nvvm_ldg_ll2(reinterpret_cast<const ll2 *>(ptr));
  longlong2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}

inline __device__ uchar2 __ldg(const uchar2 *ptr) {
  typedef unsigned char uc2 __attribute__((ext_vector_type(2)));
  uc2 rv = __nvvm_ldg_uc2(reinterpret_cast<const uc2 *>(ptr));
  uchar2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ uchar4 __ldg(const uchar4 *ptr) {
  typedef unsigned char uc4 __attribute__((ext_vector_type(4)));
  uc4 rv = __nvvm_ldg_uc4(reinterpret_cast<const uc4 *>(ptr));
  uchar4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ ushort2 __ldg(const ushort2 *ptr) {
  typedef unsigned short us2 __attribute__((ext_vector_type(2)));
  us2 rv = __nvvm_ldg_us2(reinterpret_cast<const us2 *>(ptr));
  ushort2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ ushort4 __ldg(const ushort4 *ptr) {
  typedef unsigned short us4 __attribute__((ext_vector_type(4)));
  us4 rv = __nvvm_ldg_us4(reinterpret_cast<const us4 *>(ptr));
  ushort4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ uint2 __ldg(const uint2 *ptr) {
  typedef unsigned int ui2 __attribute__((ext_vector_type(2)));
  ui2 rv = __nvvm_ldg_ui2(reinterpret_cast<const ui2 *>(ptr));
  uint2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ uint4 __ldg(const uint4 *ptr) {
  typedef unsigned int ui4 __attribute__((ext_vector_type(4)));
  ui4 rv = __nvvm_ldg_ui4(reinterpret_cast<const ui4 *>(ptr));
  uint4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ ulonglong2 __ldg(const ulonglong2 *ptr) {
  typedef unsigned long long ull2 __attribute__((ext_vector_type(2)));
  ull2 rv = __nvvm_ldg_ull2(reinterpret_cast<const ull2 *>(ptr));
  ulonglong2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}

inline __device__ float2 __ldg(const float2 *ptr) {
  typedef float f2 __attribute__((ext_vector_type(2)));
  f2 rv = __nvvm_ldg_f2(reinterpret_cast<const f2 *>(ptr));
  float2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}
inline __device__ float4 __ldg(const float4 *ptr) {
  typedef float f4 __attribute__((ext_vector_type(4)));
  f4 rv = __nvvm_ldg_f4(reinterpret_cast<const f4 *>(ptr));
  float4 ret;
  ret.w = rv[0];
  ret.x = rv[1];
  ret.y = rv[2];
  ret.z = rv[3];
  return ret;
}
inline __device__ double2 __ldg(const double2 *ptr) {
  typedef double d2 __attribute__((ext_vector_type(2)));
  d2 rv = __nvvm_ldg_d2(reinterpret_cast<const d2 *>(ptr));
  double2 ret;
  ret.x = rv[0];
  ret.y = rv[1];
  return ret;
}

// TODO: Implement these as intrinsics, so the backend can work its magic on
// these.  Alternatively, we could implement these as plain C and try to get
// llvm to recognize the relevant patterns.
inline __device__ unsigned __funnelshift_l(unsigned low32, unsigned high32,
                                           unsigned shiftWidth) {
  unsigned result;
  asm("shf.l.wrap.b32 %0, %1, %2, %3;"
      : "=r"(result)
      : "r"(low32), "r"(high32), "r"(shiftWidth));
  return result;
}
inline __device__ unsigned __funnelshift_lc(unsigned low32, unsigned high32,
                                            unsigned shiftWidth) {
  unsigned result;
  asm("shf.l.clamp.b32 %0, %1, %2, %3;"
      : "=r"(result)
      : "r"(low32), "r"(high32), "r"(shiftWidth));
  return result;
}
inline __device__ unsigned __funnelshift_r(unsigned low32, unsigned high32,
                                           unsigned shiftWidth) {
  unsigned result;
  asm("shf.r.wrap.b32 %0, %1, %2, %3;"
      : "=r"(result)
      : "r"(low32), "r"(high32), "r"(shiftWidth));
  return result;
}
inline __device__ unsigned __funnelshift_rc(unsigned low32, unsigned high32,
                                            unsigned shiftWidth) {
  unsigned ret;
  asm("shf.r.clamp.b32 %0, %1, %2, %3;"
      : "=r"(ret)
      : "r"(low32), "r"(high32), "r"(shiftWidth));
  return ret;
}

#endif // !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 320

#endif // defined(__CLANG_CUDA_INTRINSICS_H__)
