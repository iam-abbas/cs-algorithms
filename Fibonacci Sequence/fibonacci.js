// Recursive implementation
export default function fibonacci(length) {
  if (length <= 1) return 1;
  
  return fibonacci(length - 1) + fibonacci(length - 2);
}
