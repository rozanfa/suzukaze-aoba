;
; BIND data file for local loopback interface
;
$TTL	604800
@	IN	SOA	kokorondebian.com. root.kokorondebian.com. (
			      1		; Serial
			 604800		; Refresh
			  86400		; Retry
			2419200		; Expire
			 604800 )	; Negative Cache TTL
;
@	IN	NS	kokorondebian.com.
@	IN	A	192.168.10.1
www	IN	A	192.168.10.1

